##############
## Binaries ##
##############
CC = arm-none-eabi-gcc

#################
## Directories ##
#################
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
DEB_DIR = debug
SUP_DIR = startup

###########
## Files ##
###########
SRC := $(wildcard $(SRC_DIR)/*.c)
SRC += $(wildcard $(SUP_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(SRC_DIR)/$(OBJ_DIR)/%.o, $(SRC))
OBJ := $(patsubst $(SUP_DIR)/%.c, $(SRC_DIR)/$(OBJ_DIR)/%.o, $(OBJ))

LD := $(wildcard $(SUP_DIR)/*.ld)

####################
## Compiler Flags ##
####################
MARCH = cortex-m4
CFLAGS = -g -Wall -Wextra -mcpu=$(MARCH) -mthumb
LFLAGS  = -nostdlib -T $(LD) -Wl,-Map=$(DEB_DIR)/main.map

#############
## Targets ##
#############
TARGET = $(DEB_DIR)/main.elf

all: $(OBJ) $(TARGET)

$(SRC_DIR)/$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | mk_obj
	$(CC) $(CFLAGS) -c -o $@ $^

$(SRC_DIR)/$(OBJ_DIR)/%.o : $(SUP_DIR)/%.c | mk_obj
	$(CC) $(CFLAGS) -c -o $@ $^

$(TARGET) : $(OBJ) | mk_deb
	$(CC) $(LFLAGS) -o $@ $^

mk_obj:
	mkdir -p $(SRC_DIR)/$(OBJ_DIR)

mk_deb:
	mkdir -p $(DEB_DIR)

flash:
	openocd -f /usr/share/openocd/scripts/interface/stlink-v2.cfg -f /usr/share/openocd/scripts/target/stm32l4x.cfg &
	gdb-multiarch $(TARGET) -x $(SUP_DIR)/flash.gdb
	pkill openocd

debug:
	openocd -f /usr/share/openocd/scripts/interface/stlink-v2.cfg -f /usr/share/openocd/scripts/target/stm32l4x.cfg &
	gdb-multiarch $(TARGET) -x $(SUP_DIR)/debug.gdb

clean:
	rm -rf $(DEB_DIR) $(SRC_DIR)/$(OBJ_DIR)

.PHONY = mk_deb mk_obj  flash debug clean
