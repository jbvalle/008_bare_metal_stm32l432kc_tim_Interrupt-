#include <stdint.h>
#include "peripherals.h"

#define HSI_FREQ 16000000
#define TIM2_IRQn 28

void _TIM2_interrupt_GPIO_init(void){

    /*********************/
    /** Configure GPIOB **/
    /*********************/
    /** Enable GPIOB **/
    RCC->RCC_AHB2ENR |= (1 << 1);

    /** Set PB3 as OUTPUT **/
    GPIOB->GPIOx_MODER &= ~(3 << (3 * 2));
    GPIOB->GPIOx_MODER |=  (1 << (3 * 2));
    GPIOB->GPIOx_ODR |= (1 << 3);
}

void _TIM2_interrupt_configuration(uint32_t toggle_freq){

    /************************/
    /** TIM2 Configuration **/
    /************************/
    RCC->RCC_APB1ENR1 |= (1 << 0);

    /** Set PRE and ARR **/
    uint32_t toggle_frequency_TIM2 = toggle_freq;

    TIM2->TIMx_PSC = 16000 - 1;

    TIM2->TIMx_ARR = ((HSI_FREQ) / (toggle_frequency_TIM2 * TIM2->TIMx_PSC)) - 1;

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
    NVIC->ISER[0] |= (1 << (TIM2_IRQn % 32));
}

void _TIM6_GPIO_init(void){

    /************************/
    /** TIM6 Configuration **/
    /************************/
    
    /*********************/
    /** Configure GPIOA **/
    /*********************/
    /** Enable GPIOA **/
    RCC->RCC_AHB2ENR |= (1 << 0);

    /** Set PA4 as OUTPUT **/
    GPIOA->GPIOx_MODER &= ~(3 << (4 * 2));
    GPIOA->GPIOx_MODER |=  (1 << (4 * 2));
    GPIOA->GPIOx_ODR |= (1 << 4);
}

void _TIM6_halting_configuration(uint32_t toggle_freq){

    /** Enable TIM6 **/
    RCC->RCC_APB1ENR1 |= (1 << 4);

    /** Set PRE and ARR **/
    uint32_t toggle_frequency_TIM6 = toggle_freq;

    TIM6->TIMx_PSC = 16000 - 1;

    TIM6->TIMx_ARR = (HSI_FREQ / (toggle_frequency_TIM6 * TIM6->TIMx_PSC)) - 1;

    /** Reset TIM6 CNT **/
    TIM6->TIMx_CNT = 0;

    /** Start Counter **/
    TIM6->TIMx_CR1 |= 1;

    for(;;){
        /** Loop Until Overflow **/
        while(!(TIM6->TIMx_SR & 1));
        /** Reset Overflow flag **/
        TIM6->TIMx_SR = 0;
        GPIOA->GPIOx_ODR ^= (1 << 4);
    }
}
