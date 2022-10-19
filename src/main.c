#include <stdint.h>
#include <stdlib.h>
#include "peripherals.h"
#include "tim.h"

NVIC_t      *   const NVIC          = (NVIC_t       *)  0xE000E100;
RCC_t       *   const RCC           = (RCC_t        *)  0x40021000;
GPIOx_t     *   const GPIOA         = (GPIOx_t      *)  0x48000000;
GPIOx_t     *   const GPIOB         = (GPIOx_t      *)  0x48000400;
GPIOx_t     *   const GPIOC         = (GPIOx_t      *)  0x48000800;
GPTIMx_t    *   const TIM2          = (GPTIMx_t     *)  0x40000000;
BTIMx_t     *   const TIM6           = (BTIMx_t      *)  0x40001000;


void TIM2_handler(void){

    /** Reset CC Flags and Overflow Flag **/
    TIM2->TIMx_SR = 0;
    /** Toggle PA4 LED **/
    GPIOB->GPIOx_ODR ^= (1 << 3);
}

int main(void){

    /** Configure TIM2 Interrupt and toggle led depending on desired FRQ **/
    _TIM2_interrupt_GPIO_init();
    _TIM2_interrupt_configuration(13);

    /** Configure TIM6 Polling function and blink led depending on desired FRQ **/
    _TIM6_GPIO_init();
    _TIM6_halting_configuration(3);

    for(;;);
}
