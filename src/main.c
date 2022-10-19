#include <stdint.h>
#include "peripherals.h"

NVIC_t      *   const NVIC          = (NVIC_t       *)  0xE000E100;
SYSCFG_t    *   const SYSCFG        = (SYSCFG_t     *)  0x40010000;
RCC_t       *   const RCC           = (RCC_t        *)  0x40021000;
GPIOx_t     *   const GPIOA         = (GPIOx_t      *)  0x48000000;
GPIOx_t     *   const GPIOB         = (GPIOx_t      *)  0x48000400;
GPIOx_t     *   const GPIOC         = (GPIOx_t      *)  0x48000800;
GPTIMx_t    *   const TIM2          = (GPTIMx_t     *)  0x40000000;

void wait_ms(int time){
    for(int i = 0; i < time; i++){
        for(int j = 0; j < 1600; j++);
    }
}

void blink(){
    GPIOA->GPIOx_ODR ^= (1 << 4);
    GPIOA->GPIOx_ODR ^= (1 << 8);
    wait_ms(100);
}
int main(void){
   
    /** Enable GPIOA **/
    RCC->RCC_AHB2ENR |= (1 << 0);

    /** Configure GPIOA **/
    GPIOA->GPIOx_MODER &= ~(3 << (4 * 2));
    GPIOA->GPIOx_MODER |=  (1 << (4 * 2));

    GPIOA->GPIOx_MODER &= ~(3 << (8 * 2));
    GPIOA->GPIOx_MODER |=  (1 << (8 * 2));

    GPIOA->GPIOx_ODR |=  (1 << 4);
    GPIOA->GPIOx_ODR &= ~(1 << 8);

    for(;;){
        blink();
    }
} 
