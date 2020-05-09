/*!
 * @file   PeripheralClock.c
 * @brief  Configuration of peripheral clock for ADC
 * @author 
 * @date
 */

#include <stdint.h>

#define ADC_BASE_ADDRESS        0x40012000UL
#define ADC_CR1_REG_OFFSET      0x04UL
#define ADC_CR1_REG_ADDRESS     (ADC_BASE_ADDRESS + ADC_CR1_REG_OFFSET)
#define RCC_BASE_ADDRESS        0x40023800UL
#define RCC_APB2_ENR_OFFSET     0x44UL
#define RCC_APB2_ENR_ADDRESS    (RCC_BASE_ADDRESS + RCC_APB2_ENR_OFFSET)

void main(void)
{
    uint32_t *pAdcCtrlReg = (uint32_t *) ADC_CR1_REG_ADDRESS;
    uint32_t *pRccApb2Enr = (uint32_t *) RCC_APB2_ENR_ADDRESS;
    
    *pAdcCtrlReg |= (1 << 8);  //Enable the peripheral clock for ADC1
    *pRccApb2Enr |= (1 << 8);  //Modify the ADC control register

    while(1)
    {

    }
}
