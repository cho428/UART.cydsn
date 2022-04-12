/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "timer.h"

void timerCallback(){
    if(countLED1 > 0) countLED1--;
    if(countLED2 > 0) countLED2--;
}
void initTimer(){
    Cy_SysTick_Init(CY_SYSTICK_CLOCK_SOURCE_CLK_IMO,(8000000/1000)-1);
    for(uint8 i=0;i<CY_SYS_SYST_NUM_OF_CALLBACKS;i++){
        if(Cy_SysTick_GetCallback(i) == NULL){
            Cy_SysTick_SetCallback(i,timerCallback);
        }
     }
}

/* [] END OF FILE */
