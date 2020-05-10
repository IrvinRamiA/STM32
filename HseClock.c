/*!
 * @file   HsiClock.c
 * @brief  Configuration of HSE clock as output in GPIO
 * @author 
 * @date
 */

#include <stdint.h>

#define RCC_BASE_ADDRESS 0x40023800UL
#define RCC_CFGR_REG_OFFSET 0x08UL
#define RCC_CR_REG_OFFSET 0x00UL
#define RCC_CFGR_REG_ADDRESS (RCC_BASE_ADDRESS + RCC_CFGR_REG_OFFSET)
#define RCC_CR_REG_ADDRESS (RCC_BASE_ADDRESS + RCC_CR_REG_OFFSET)
#define GPIOA_BASE_ADDRESS 0x40020000UL

void main(void)
{
    uint32_t *pRccCrReg = (uint32_t *)RCC_CR_REG_ADDRESS;
    uint32_t *pRccCfgrReg = (uint32_t *)RCC_CFGR_REG_ADDRESS;

    // Enable the HSE clock using HSEON bit (RCC_CR)
    *pRccCrReg |= (1 << 16);

    // Wait until HSE clock from the external crystal stabilizes
    // (only if crystal is connected)
    while (!(*pRccCrReg & (1 << 17)))
        ;

    // Switch the system clock to HSE (RCC_CFGR)
    *pRccCfgrReg |= (1 << 0);

    // Configure the RCC_CFGR MCO1 bit fields to select HSE as clock source
    *pRccCfgrReg |= (1 << 22);

    // Configure MCO1 prescaler with divisor as 4
    *pRccCfgrReg |= (1 << 25);
    *pRccCfgrReg |= (1 << 26);

    // Configure PA8 to AF0 mode to behave as MCO1 signal
    // Enable the peripheral clock for GPIOA peripheral
    uint32_t *pRCCAhb1Enr = (uint32_t *)(RCC_BASE_ADDRESS + 0x30);
    *pRCCAhb1Enr |= (1 << 0); 

    // Configure the mode of GPIOA pin 8 as alternate function mode
    uint32_t *pGPIOAModeReg = (uint32_t *)(GPIOA_BASE_ADDRESS + 00);
    *pGPIOAModeReg &= ~(0x3 << 16); 
    *pGPIOAModeReg |= (0x2 << 16);

    // Configure the alternation function register to set the mode 0 for PA8
    uint32_t *pGPIOAAltFunHighReg = (uint32_t *)(GPIOA_BASE_ADDRESS + 0x24);
    *pGPIOAAltFunHighReg &= ~(0xf << 0);

    while (1)
    {

    }
}