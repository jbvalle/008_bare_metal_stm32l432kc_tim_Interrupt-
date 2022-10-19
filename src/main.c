#include <stdint.h>
#include "peripherals.h"

NVIC_t      *   const NVIC          = (NVIC_t       *)  0xE000E100;
SYSCFG_t    *   const SYSCFG        = (SYSCFG_t     *)  0x40010000;
RCC_t       *   const RCC           = (RCC_t        *)  0x40021000;
GPIOx_t     *   const GPIOA         = (GPIOx_t      *)  0x48000000;
GPIOx_t     *   const GPIOB         = (GPIOx_t      *)  0x48000400;
GPIOx_t     *   const GPIOC         = (GPIOx_t      *)  0x48000800;
GPTIMx_t    *   const TIM2          = (GPTIMx_t     *)  0x40000000;

int main(void){
   

    RCC->RCC_AHB2ENR |= (1 << 0);
    for(;;);
} 
