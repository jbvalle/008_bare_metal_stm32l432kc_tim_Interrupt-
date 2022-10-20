#ifndef TIM_H
#define TIM_H
#include <stdint.h>

void _TIM2_interrupt_GPIO_init(void (*)(void));
void _TIM2_interrupt_configuration(uint32_t toggle_freq);

void _TIM6_GPIO_init(void);
void _TIM6_halting_configuration(uint32_t toggle_freq);

#endif
