/*!
 * @file   HsiClock.c
 * @brief  Configuration of HSI clock as output in GPIO
 * @author 
 * @date
 */

#include <stdint.h>

#define RCC_BASE_ADDRESS        0x40023800UL
#define RCC_CFGR_REG_OFFSET     0x08UL
#define RCC_CFGR_REG_ADDRESS    (RCC_BASE_ADDRESS + RCC_CFGR_REG_OFFSET)
#define GPIOA_BASE_ADDRESS      0x40020000UL

void main(void)
{    
    // RCC_CFGR (RCC clock configuration register)
    // MCO1 [22:21] 
    // HSI as clock surce
    uint32_t *pRccCfgrReg = (uint32_t *) RCC_CFGR_REG_ADDRESS;
    *pRccCfgrReg &= ~(0x03 << 21);

    //Configure MCO1 prescaler
	*pRccCfgrReg |= ( 1 << 25);
	*pRccCfgrReg |= ( 1 << 26);

    // RCC_AHB1ENR (RCC AHB1 peripheral clock enable register)
    // GPIOAEN [0] 
    // Enable the peripheral clock for GPIOA peripheral
    uint32_t *pRccAhb1Enr = (uint32_t *) (RCC_BASE_ADDRESS + 0x30);
    *pRccAhb1Enr |= (1 << 0);

    // Configure the mode of GPIOA pin as alternate function mode
    uint32_t *pGpioModeReg = (uint32_t *) (GPIOA_BASE_ADDRESS + 0x00);
    *pGpioModeReg &= ~(0X03 << 16);
    *pGpioModeReg |= (0X02 << 16);

    // Configure the alternate function register to set the mode 0 for PA8
    uint32_t *pGpioAltFunHighReg = (uint32_t *) (GPIOA_BASE_ADDRESS + 0x24);
    *pGpioAltFunHighReg &= ~(0x0F << 0);

    while(1)
    {

    }
}