#include <stdint.h>

extern uint32_t _estack;
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

extern int main(void);

/** Internal Processor Peripherals **/
void Reset_handler(void);
void NMI_handler                    (void)__attribute__((weak, alias("Default_handler")));
void HardFault_handler              (void)__attribute__((weak, alias("Default_handler")));
void MemManage_handler              (void)__attribute__((weak, alias("Default_handler")));
void BusFault_handler               (void)__attribute__((weak, alias("Default_handler")));
void UsuageFault_handler            (void)__attribute__((weak, alias("Default_handler")));
void SVCall_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DebugMonitor_handler           (void)__attribute__((weak, alias("Default_handler")));
void PendSV_handler                 (void)__attribute__((weak, alias("Default_handler")));
void Systick_handler                (void)__attribute__((weak, alias("Default_handler")));
/** External Peripheral Handlers **/
void WWDG_handler                   (void)__attribute__((weak, alias("Default_handler")));
void PVD_PVM_handler                (void)__attribute__((weak, alias("Default_handler")));
void RTC_TAMP_STAMP_CSS_LSE_handler (void)__attribute__((weak, alias("Default_handler")));
void RTC_WKUP_handler               (void)__attribute__((weak, alias("Default_handler")));
void FLASH_handler                  (void)__attribute__((weak, alias("Default_handler")));
void RCC_handler                    (void)__attribute__((weak, alias("Default_handler")));
void EXTI0_handler                  (void)__attribute__((weak, alias("Default_handler")));
void EXTI1_handler                  (void)__attribute__((weak, alias("Default_handler")));
void EXTI2_handler                  (void)__attribute__((weak, alias("Default_handler")));
void EXTI3_handler                  (void)__attribute__((weak, alias("Default_handler")));
void EXTI4_handler                  (void)__attribute__((weak, alias("Default_handler")));
//
void DMA1_CH1_handler               (void)__attribute__((weak, alias("Default_handler")));
void DMA1_CH2_handler               (void)__attribute__((weak, alias("Default_handler")));
void DMA1_CH3_handler               (void)__attribute__((weak, alias("Default_handler")));
void DMA1_CH4_handler               (void)__attribute__((weak, alias("Default_handler")));
void DMA1_CH5_handler               (void)__attribute__((weak, alias("Default_handler")));
void DMA1_CH6_handler               (void)__attribute__((weak, alias("Default_handler")));
void DMA1_CH7_handler               (void)__attribute__((weak, alias("Default_handler")));
void ADC1_2_handler                 (void)__attribute__((weak, alias("Default_handler")));
void CAN1_TX_handler                (void)__attribute__((weak, alias("Default_handler")));
void CAN1_RX0_handler               (void)__attribute__((weak, alias("Default_handler")));
//
void CAN1_RX1_handler               (void)__attribute__((weak, alias("Default_handler")));
void CAN1_SCE_handler               (void)__attribute__((weak, alias("Default_handler")));
void EXTI9_5__handler               (void)__attribute__((weak, alias("Default_handler")));
void TIM1_BRK_TIM15_handler         (void)__attribute__((weak, alias("Default_handler")));
void TIM1_UP_TIM16_handler          (void)__attribute__((weak, alias("Default_handler")));
void TIM1_TRG_COM_handler           (void)__attribute__((weak, alias("Default_handler")));
void TIM1_CC_handler                (void)__attribute__((weak, alias("Default_handler")));
void TIM2_handler                   (void)__attribute__((weak, alias("Default_handler")));
void TIM3_handler                   (void)__attribute__((weak, alias("Default_handler")));
//
void I2C1_EV_handler                (void)__attribute__((weak, alias("Default_handler")));
void I2C1_ER_handler                (void)__attribute__((weak, alias("Default_handler")));
void I2C2_EV_handler                (void)__attribute__((weak, alias("Default_handler")));
void I2C2_ER_handler                (void)__attribute__((weak, alias("Default_handler")));
void SPI1_handler                   (void)__attribute__((weak, alias("Default_handler")));
void SPI2_handler                   (void)__attribute__((weak, alias("Default_handler")));
void USART1_handler                 (void)__attribute__((weak, alias("Default_handler")));
void USART2_handler                 (void)__attribute__((weak, alias("Default_handler")));
void USART3_handler                 (void)__attribute__((weak, alias("Default_handler")));
void EXTI15_10_handler              (void)__attribute__((weak, alias("Default_handler")));
void RTC_ALARM_handler              (void)__attribute__((weak, alias("Default_handler")));
//
void SDMMC1_handler                 (void)__attribute__((weak, alias("Default_handler")));
void SPI3_handler                   (void)__attribute__((weak, alias("Default_handler")));
void UART4_handler                  (void)__attribute__((weak, alias("Default_handler")));
void TIM6_DACUNDER_handler          (void)__attribute__((weak, alias("Default_handler")));
void TIM7_handler                   (void)__attribute__((weak, alias("Default_handler")));
void DMA2_CH1                       (void)__attribute__((weak, alias("Default_handler")));
void DMA2_CH2                       (void)__attribute__((weak, alias("Default_handler")));
void DMA2_CH3                       (void)__attribute__((weak, alias("Default_handler")));
void DMA2_CH4                       (void)__attribute__((weak, alias("Default_handler")));
void DMA2_CH5                       (void)__attribute__((weak, alias("Default_handler")));
//
void DFSDM1_FLT0_handler            (void)__attribute__((weak, alias("Default_handler")));
void DFSDM1_FLT1_handler            (void)__attribute__((weak, alias("Default_handler")));
void COMP_handler                   (void)__attribute__((weak, alias("Default_handler")));
void LPTIM1_handler                 (void)__attribute__((weak, alias("Default_handler")));
void LPTIM2_handler                 (void)__attribute__((weak, alias("Default_handler")));
void USB_FS_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_CH6_handler               (void)__attribute__((weak, alias("Default_handler")));
void DMA2_CH7_handler               (void)__attribute__((weak, alias("Default_handler")));
void LPUART1_handler                (void)__attribute__((weak, alias("Default_handler")));
void QUADSPI_handler                (void)__attribute__((weak, alias("Default_handler")));
//
void I2C3_EV_handler                (void)__attribute__((weak, alias("Default_handler")));
void I2C3_ER_handler                (void)__attribute__((weak, alias("Default_handler")));
void SAI1_handler                   (void)__attribute__((weak, alias("Default_handler")));
//
void SWPMI1_handler                 (void)__attribute__((weak, alias("Default_handler")));
void TSC_handler                    (void)__attribute__((weak, alias("Default_handler")));
void LCD_handler                    (void)__attribute__((weak, alias("Default_handler")));
void AES_handler                    (void)__attribute__((weak, alias("Default_handler")));
void RNG_handler                    (void)__attribute__((weak, alias("Default_handler")));
void FPU_handler                    (void)__attribute__((weak, alias("Default_handler")));
void CRS_handler                    (void)__attribute__((weak, alias("Default_handler")));
void I2C4_EV_handler                (void)__attribute__((weak, alias("Default_handler")));
void I2C4_ER_handler                (void)__attribute__((weak, alias("Default_handler")));



/** Vector table **/
__attribute__ ((section(".isr_vector")))
void (* const fpn_vector[])(void) = {
    (void (*)(void))(&_estack),
    Reset_handler,
    NMI_handler,
    HardFault_handler,
    MemManage_handler,
    BusFault_handler,
    UsuageFault_handler,
    0,
    0,
    0,
    0,
    SVCall_handler,
    DebugMonitor_handler,
    0,
    PendSV_handler,
    Systick_handler,
    WWDG_handler,
    PVD_PVM_handler,
    RTC_TAMP_STAMP_CSS_LSE_handler,
    RTC_WKUP_handler,
    FLASH_handler,
    RCC_handler,
    EXTI0_handler,
    EXTI1_handler,
    EXTI2_handler,
    EXTI3_handler,
    EXTI4_handler,
    DMA1_CH1_handler,
    DMA1_CH2_handler,
    DMA1_CH3_handler,
    DMA1_CH4_handler,
    DMA1_CH5_handler,
    DMA1_CH6_handler,
    DMA1_CH7_handler,
    ADC1_2_handler,
    CAN1_TX_handler,
    CAN1_RX0_handler,
    CAN1_RX1_handler,
    CAN1_SCE_handler,
    EXTI9_5__handler,
    TIM1_BRK_TIM15_handler,
    TIM1_UP_TIM16_handler,
    TIM1_TRG_COM_handler,
    TIM1_CC_handler,
    TIM2_handler,
    0,
    0,
    I2C1_EV_handler,
    I2C1_ER_handler,
    0,
    0,
    SPI1_handler,
    0,
    USART1_handler,
    USART2_handler,
    0,
    EXTI15_10_handler,
    RTC_ALARM_handler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SPI3_handler,
    0,
    0,
    TIM6_DACUNDER_handler,
    TIM7_handler,
    DMA2_CH1,
    DMA2_CH2,
    DMA2_CH3,
    DMA2_CH4,
    DMA2_CH5,
    0,
    0,
    0,
    COMP_handler,
    LPTIM1_handler,
    LPTIM2_handler,
    USB_FS_handler,
    DMA2_CH6_handler,
    DMA2_CH7_handler,
    LPUART1_handler,
    QUADSPI_handler,
    I2C3_EV_handler,
    I2C3_ER_handler,
    SAI1_handler,
    0,
    SWPMI1_handler,
    TSC_handler,
    0,
    0,
    RNG_handler,
    FPU_handler,
    CRS_handler
};

void Default_handler(void){
    for(;;);
}

void Reset_handler(void){
    /** 1. Copy Data from Flash to SRAM **/
    uint32_t *pSrc = (uint32_t *)(&_estack);
    uint32_t *pDst = (uint32_t *)(&_sdata);
    uint32_t size = (uint32_t)(&_edata) - (uint32_t)(&_sdata);
    
    for(uint32_t i = 0; i < size; i++){

        *pDst++ = *pSrc++;
    }
    /** 2. Initialize bss section with zero **/
    pDst = (uint32_t *)(&_sbss);
    size = (uint32_t)(&_ebss) - (uint32_t)(&_sbss);

    for(uint32_t i = 0; i < size; i++){

        *pDst++ = 0;
    }

    /** 3. Call main() **/
    main();
}

