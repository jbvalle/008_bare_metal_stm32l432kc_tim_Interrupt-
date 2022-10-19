#include <stdint.h>
#include "peripherals.h"

#define HSI_FREQ 16000000
#define TIM2_IRQn 28

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
    GPIOA->GPIOx_ODR ^= (1 << 4);
}

int main(void){

    /*********************/
    /** Configure GPIOB **/
    /*********************/
    /** Enable GPIOA **/
    RCC->RCC_AHB2ENR |= (1 << 0);

    /** Set PB3 as OUTPUT **/
    GPIOB->GPIOx_MODER &= ~(3 << (4 * 2));
    GPIOB->GPIOx_MODER |=  (1 << (4 * 2));
    GPIOB->GPIOx_ODR |= (1 << 4);

    /************************/
    /** TIM2 Configuration **/
    /************************/
    RCC->RCC_APB1ENR1 |= (1 << 0);
    
    /** Set PRE and ARR **/
    uint32_t toggle_frequency_TIM2 = 8;

    TIM2->TIMx_PSC = 16000 - 1;

    TIM2->TIMx_ARR = (HSI_FREQ / (toggle_frequency_TIM2 * TIM2->TIMx_PSC)) - 1;

    /** Set Compare Value **/
    TIM2->TIMx_CCR1 = 1;

    /** Enable Compare Register **/
    TIM2->TIMx_CCER |= 1;

    /** Reset TIM6 CNT **/
    TIM2->TIMx_CNT = 0;

    /** Start Counter **/
    TIM2->TIMx_CR1 |= 1;

    /** Enable Interrupt **/
    TIM2->TIMx_DIER |= (1 << 1);

    /** Enable IRQ in NVIC **/
    NVIC->ISER[0] |= (1 << (TIM2_IRQn & 32));

    /************************/
    /** TIM6 Configuration **/
    /************************/

    /** Enable TIM6 **/
    //RCC->RCC_APB1ENR1 |= (1 << 1);

    /** Set PRE and ARR **/
    //uint32_t toggle_frequency_TIM6 = 2;

    //TIM6->TIMx_PSC = 16000 - 1;

    //TIM6->TIMx_ARR = (HSI_FREQ / (toggle_frequency_TIM6 * TIM6->TIMx_PSC)) - 1;

    /** Reset TIM6 CNT **/
    //TIM6->TIMx_CNT = 0;

    /** Start Counter **/
    //TIM6->TIMx_CR1 |= 1;

    for(;;){

        /** Loop Until Overflow has been reached **/ 
        while(!(TIM6->TIMx_SR & 1));

        /** Reset Overflow Flag **/
        TIM6->TIMx_SR &= ~1;

        /** Toggle PB3 upon overflow **/
        GPIOB->GPIOx_ODR ^= (1 << 3);
    }
}
