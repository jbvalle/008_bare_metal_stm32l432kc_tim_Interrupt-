/** Entry Point **/
ENTRY(Reset_handler)

/** Top of Stack **/
_estack = ORIGIN(SRAM) + LENGTH(SRAM);

/** Define Memory **/
MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 256K
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH =  64K
}

/** Define OUTPUT Sections **/
SECTIONS
{
    .isr_vector :
    {
        . = ALIGN(4);
        *(.isr_vector)
        . = ALIGN(4);
    }> FLASH

    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(4);
    }> FLASH

    _etext = LOADADDR(.data);

    .data :
    {
       . = ALIGN(4);
       _sdata = .;
       *(.data)
       *(.data.*)
       . = ALIGN(4);
       _edata = .;
    }> SRAM AT> FLASH

    .bss :
    {
       . = ALIGN(4);
       _sbss = .;
       *(.bss)
       *(.bss.*)
       *(COMMON)
       . = ALIGN(4);
       _ebss = .;
    }> SRAM
}
