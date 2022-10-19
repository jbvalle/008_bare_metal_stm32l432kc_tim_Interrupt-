#ifndef PERIPHERALS_H
#define PERIPHERALS_H
#include <stdint.h>

typedef struct RCC_t{
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_ICSCR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_PLLCFGR;
    volatile uint32_t RCC_PLLSAI1CFGR;
    volatile uint32_t res1;
    volatile uint32_t RCC_CIER;
    volatile uint32_t RCC_CIFR;
    volatile uint32_t RCC_CICR;
    volatile uint32_t res2;
    volatile uint32_t RCC_AHB1RSTR;
    volatile uint32_t RCC_AHB2RSTR;
    volatile uint32_t RCC_AHB3RSTR;
    volatile uint32_t res3;
    volatile uint32_t RCC_APB1RSTR1;
    volatile uint32_t RCC_APB1RSTR2;
    volatile uint32_t RCC_APB2RSTR2;
    volatile uint32_t res4;
    volatile uint32_t RCC_AHB1ENR;
    volatile uint32_t RCC_AHB2ENR;
    volatile uint32_t RCC_AHB3ENR;
    volatile uint32_t res5;
    volatile uint32_t RCC_APB1ENR1;
    volatile uint32_t RCC_APB1ENR2;
    volatile uint32_t RCC_APB2ENR;
    volatile uint32_t res6;
    volatile uint32_t RCC_AHB1SMENR;
    volatile uint32_t RCC_AHB2SMENR;
    volatile uint32_t RCC_AHB3SMENR;
    volatile uint32_t res7;
    volatile uint32_t RCC_APB1SMENR1;
    volatile uint32_t RCC_APB1SMENR2;
    volatile uint32_t RCC_APB2SMENR;
    volatile uint32_t res8;
    volatile uint32_t RCC_CCIPR;
    volatile uint32_t res9;
    volatile uint32_t RCC_BDCR;
    volatile uint32_t RCC_CSR;
    volatile uint32_t RCC_CRRCR;
    volatile uint32_t RCC_CCIPR2;
}RCC_t;

typedef struct GPIOx_t{
    volatile uint32_t GPIOx_MODER;
    volatile uint32_t GPIOx_OTYPER;
    volatile uint32_t GPIOx_OSPEEDR;
    volatile uint32_t GPIOx_PUPDR;
    volatile uint32_t GPIOx_IDR;
    volatile uint32_t GPIOx_ODR;
    volatile uint32_t GPIOx_BSRR;
    volatile uint32_t GPIOx_LCKR;
    volatile uint32_t GPIOx_AFRL;
    volatile uint32_t GPIOx_AFRH;
    volatile uint32_t GPIOx_BRR;
}GPIOx_t;

typedef struct GPTIMx_t{
    volatile uint32_t TIMx_CR1;
    volatile uint32_t TIMx_CR2;
    volatile uint32_t TIMx_CMCR;
    volatile uint32_t TIMx_DIER;
    volatile uint32_t TIMx_SR;
    volatile uint32_t TIMx_EGR;
    volatile uint32_t TIMx_CCMR1;
    volatile uint32_t TIMx_CCMR2;
    volatile uint32_t TIMx_CCER;
    volatile uint32_t TIMx_CNT;
    volatile uint32_t TIMx_PSC;
    volatile uint32_t TIMx_ARR;
    volatile uint32_t res1;
    volatile uint32_t TIMx_CCR1;
    volatile uint32_t TIMx_CCR2;
    volatile uint32_t TIMx_CCR3;
    volatile uint32_t TIMx_CCR4;
    volatile uint32_t res2;
    volatile uint32_t TIMx_DCR;
    volatile uint32_t TIMx_DMAR;
    volatile uint32_t TIMx_OR1;
    volatile uint32_t res3;
    volatile uint32_t res4;
    volatile uint32_t res5;
    volatile uint32_t TIMx_OR2;
    volatile uint32_t res6;
    volatile uint32_t res7;
    volatile uint32_t res8;
}GPTIMx_t;

typedef struct BTIMx_t{
    volatile uint32_t TIMx_CR1;
    volatile uint32_t TIMx_CR2;
    volatile uint32_t res1;
    volatile uint32_t TIMx_DIER;
    
    volatile uint32_t TIMx_SR;
    volatile uint32_t TIMx_EGR;
    volatile uint32_t res2;
    volatile uint32_t res3;
    
    volatile uint32_t res4;
    volatile uint32_t TIMx_CNT;
    volatile uint32_t TIMx_PSC;
    volatile uint32_t TIMx_ARR;
}BTIMx_t;


typedef struct NVIC_t{
    volatile uint32_t ISER[8];
    volatile uint32_t ICER[8];
    volatile uint32_t ISPR[8];
    volatile uint32_t ICPR[8];
    volatile uint32_t IABR[8];
    volatile uint32_t IPR[8];
    volatile uint32_t STIR[8];
}NVIC_t;
#endif
