/*!
 * @file   VolatileKeyword.c
 * @brief  Example of volatile keyword use
 * @author 
 * @date
 */

#include <stdint.h>

#define SRAM_ADDRESS1   0x20000004U

void main(void)
{
  uint32_t value = 0;
  volatile uint32_t *ptrSram = (uint32_t *) SRAM_ADDRESS1;

  while(1)
  {
    value = *ptrSram;
    if(value)
    {
      break;
    }
  }

  while(1)
  {

  }
}


