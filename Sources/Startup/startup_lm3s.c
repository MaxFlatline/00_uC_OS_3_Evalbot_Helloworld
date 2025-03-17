// Standart includes
#include <stdint.h>

// Linker symbols that are used to prepare the vector table
extern uint32_t _top_of_ram_stack_start; 
extern uint32_t _data;
extern uint32_t _edata;
extern uint32_t _sidata;
extern uint32_t _bss;
extern uint32_t _ebss;

// Extern function declarations
extern void main(void);

// Private function declarations
void Reset_Handler(void);
void Default_Handler(void);

// All handlers will default to Default_Handler until they are reimplemented in the application code
void NMI_Handler(void)                          __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)                   __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)                          __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)                       __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
//----------------------------------------------------------------------------------------------
void GPIOPortA_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void GPIOPortB_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void GPIOPortC_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void GPIOPortD_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void GPIOPortE_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void UART0_Handler(void)                        __attribute__((weak, alias("Default_Handler")));
void UART1_Handler(void)                        __attribute__((weak, alias("Default_Handler")));
void SSI0_Handler(void)                         __attribute__((weak, alias("Default_Handler")));
void I2C0_Handler(void)                         __attribute__((weak, alias("Default_Handler")));
void PWMFault_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void PWMGen0_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void PWMGen1_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void PWMGen2_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void QEI0_Handler(void)                         __attribute__((weak, alias("Default_Handler")));
void ADC0Seq0_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void ADC0Seq1_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void ADC0Seq2_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void ADC0Seq3_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void Watchdod_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void Timer0A_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void Timer0B_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void Timer1A_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void Timer1B_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void Timer2A_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void Timer2B_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void Comp0_Handler(void)                        __attribute__((weak, alias("Default_Handler")));
void Comp1_Handler(void)                        __attribute__((weak, alias("Default_Handler")));
void Comp2_Handler(void)                        __attribute__((weak, alias("Default_Handler")));
void SysCtrl_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void FlashCtrl_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void GPIOPortF_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void GPIOPortG_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void GPIOPortH_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void UART2_Handler(void)                        __attribute__((weak, alias("Default_Handler")));
void SSI1_Handler(void)                         __attribute__((weak, alias("Default_Handler")));
void Timer3A_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void Timer3B_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void I2C1_Handler(void)                         __attribute__((weak, alias("Default_Handler")));
void QEI1_Handler(void)                         __attribute__((weak, alias("Default_Handler")));
void CAN0_Handler(void)                         __attribute__((weak, alias("Default_Handler")));
void CAN1_Handler(void)                         __attribute__((weak, alias("Default_Handler")));
void Ethernet_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void USB_Handler(void)                          __attribute__((weak, alias("Default_Handler")));
void PWMGen3_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void UDMA_Handler(void)                         __attribute__((weak, alias("Default_Handler")));
void UDMAErr_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void ADC1Seq0_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void ADC1Seq1_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void ADC1Seq2_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void ADC1Seq3_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void I2S0_Handler(void)                         __attribute__((weak, alias("Default_Handler")));
void EPI_Handler(void)                          __attribute__((weak, alias("Default_Handler")));
void GPIOPortJ_Handler(void)                    __attribute__((weak, alias("Default_Handler")));


// Vector table
uint32_t vector_table[] __attribute__((section(".isr_vector"))) = {
    (uint32_t)&_top_of_ram_stack_start,   // Initial Stack Pointer
    //--------| System Exeption Handlers |--------------------------
    (uint32_t)&Reset_Handler,             // Reset Handler
    (uint32_t)&NMI_Handler,               // Non-Mascable Interrupt Handler
    (uint32_t)&HardFault_Handler,         // Hard Fault Handler
    (uint32_t)&MemManage_Handler,         // MPU Fault Handler
    (uint32_t)&BusFault_Handler,          // Bus Fault Handler
    (uint32_t)&UsageFault_Handler,        // Usage Fault Handler
    0, 0, 0, 0,                           // Reserved 7-10
    (uint32_t)&SVC_Handler,               // SVCall Handler
    (uint32_t)&DebugMon_Handler,          // Debug Monitor Handler
    0,                                    // Reserved 13
    (uint32_t)&PendSV_Handler,            // PendSV Handler
    (uint32_t)&SysTick_Handler,           // SysTick Handler
    //--------| Peripheral Interrupts Handlers |---------
    (uint32_t)&GPIOPortA_Handler,         // GPIO Port A
    (uint32_t)&GPIOPortB_Handler,         // GPIO Port B
    (uint32_t)&GPIOPortC_Handler,         // GPIO Port C
    (uint32_t)&GPIOPortD_Handler,         // GPIO Port D
    (uint32_t)&GPIOPortE_Handler,         // GPIO Port E
    (uint32_t)&UART0_Handler,             // UART0 Rx and Tx
    (uint32_t)&UART1_Handler,             // UART1 Rx and Tx
    (uint32_t)&SSI0_Handler,              // SSI0 Rx and Tx
    (uint32_t)&I2C0_Handler,              // I2C0 Master and Slave
    (uint32_t)&PWMFault_Handler,          // PWM Fault
    (uint32_t)&PWMGen0_Handler,           // PWM Generator 0
    (uint32_t)&PWMGen1_Handler,           // PWM Generator 1
    (uint32_t)&PWMGen2_Handler,           // PWM Generator 2
    (uint32_t)&QEI0_Handler,              // Quadrature Encoder 0
    (uint32_t)&ADC0Seq0_Handler,          // ADC0 Sequence 0
    (uint32_t)&ADC0Seq1_Handler,          // ADC0 Sequence 1
    (uint32_t)&ADC0Seq2_Handler,          // ADC0 Sequence 2
    (uint32_t)&ADC0Seq3_Handler,          // ADC0 Sequence 3
    (uint32_t)&Watchdod_Handler,          // Watchdog timer
    (uint32_t)&Timer0A_Handler,           // Timer 0 subtimer A
    (uint32_t)&Timer0B_Handler,           // Timer 0 subtimer B
    (uint32_t)&Timer1A_Handler,           // Timer 1 subtimer A
    (uint32_t)&Timer1B_Handler,           // Timer 1 subtimer B
    (uint32_t)&Timer2A_Handler,           // Timer 2 subtimer A
    (uint32_t)&Timer2B_Handler,           // Timer 2 subtimer B
    (uint32_t)&Comp0_Handler,             // Analog Comparator 0
    (uint32_t)&Comp1_Handler,             // Analog Comparator 1
    (uint32_t)&Comp2_Handler,             // Analog Comparator 2
    (uint32_t)&SysCtrl_Handler,           // System Control (PLL, OSC, BO)
    (uint32_t)&FlashCtrl_Handler,         // FLASH Control
    (uint32_t)&GPIOPortF_Handler,         // GPIO Port F
    (uint32_t)&GPIOPortG_Handler,         // GPIO Port G
    (uint32_t)&GPIOPortH_Handler,         // GPIO Port H
    (uint32_t)&UART2_Handler,             // UART2 Rx and Tx
    (uint32_t)&SSI1_Handler,              // SSI1 Rx and Tx
    (uint32_t)&Timer3A_Handler,           // Timer 3 subtimer A
    (uint32_t)&Timer3B_Handler,           // Timer 3 subtimer B
    (uint32_t)&I2C1_Handler,              // I2C1 Master and Slave
    (uint32_t)&QEI1_Handler,              // Quadrature Encoder 1
    (uint32_t)&CAN0_Handler,              // CAN0
    (uint32_t)&CAN1_Handler,              // CAN1
    0,
    (uint32_t)&Ethernet_Handler,          // Ethernet
    0,
    (uint32_t)&USB_Handler,               // USB
    (uint32_t)&PWMGen3_Handler,           // PWM Generator 3
    (uint32_t)&UDMA_Handler,              // uDMA  Software
    (uint32_t)&UDMAErr_Handler,           // uDMA errors
    (uint32_t)&ADC1Seq0_Handler,          // ADC1 Sequence 0
    (uint32_t)&ADC1Seq1_Handler,          // ADC1 Sequence 1
    (uint32_t)&ADC1Seq2_Handler,          // ADC1 Sequence 2
    (uint32_t)&ADC1Seq3_Handler,          // ADC1 Sequence 3
    (uint32_t)&I2S0_Handler,              // I2S0
    (uint32_t)&EPI_Handler,               // External Periphery Interface
    (uint32_t)&GPIOPortJ_Handler,         // GPIO Port J
    0
};

//-----------------------------------------------------------------------
void Reset_Handler(void)
{
    // Copy .data section from FLASH to RAM
    uint32_t size = (uint32_t)&_edata - (uint32_t)&_data;
    uint8_t *pDst = (uint8_t *)&_data; // pointer to start of RAM
    uint8_t *pSrc = (uint8_t *)&_sidata; // pointer to start of Flash

    for(uint32_t i = 0; i < size; i++)
    {
        *pDst++ = *pSrc++;
    }

    // Initialize the .bss section to zero in RAM
    __asm("  ldr     r0, =_bss\n"
          "  ldr     r1, =_ebss\n"
          "  mov     r2, #0\n"
          "  .thumb_func\n"
          "zero_loop:\n"
          "    cmp     r0, r1\n"
          "    it      lt\n"
          "    strlt   r2, [r0], #4\n"
          "    blt     zero_loop");
   /* size = (uint32_t)&_ebss - (uint32_t)&_bss;
    pDst = (uint8_t *)_bss;

    for(uint32_t i = 0; i < size; i++)
    {
        *pDst++ = 0;
    }*/

    // do other initializations if an app requires so before getting to main function

    //give control to main() function
    main();

    while(1)
    {
        // Should not get here unless something wrong
    }
}


// Default Handler
void Default_Handler(void)
{
    while(1)
    {
    }
}
