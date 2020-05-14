/*
 * 
 *
 * Created: 2/23/2020 9:32:04 PM
 * Author : MENNA
 */ 

#include "DIO.h"
#include "TMU.h"
#include "avr/interrupt.h"


/**=========================================================================*
 *								Defines & Globals							*
 *==========================================================================*/


/**=========================================================================*
 *							TMU TASKS				                    	*
 *==========================================================================*/

void toggle1(void){
	DDRA = 0x0F ;
	PORTA_DATA ^= 0x0F ;
	
}

void toggle2(void){
	DDRA = 0xFF ;
	PORTA_DATA ^= 0xF0 ;
	
}



/**=========================================================================*
 *								Main Function								*
 *==========================================================================*/

int main(void)
{
	
	
/**=========================================================================*
 *								TMU TEST CODE								*
 *==========================================================================*/
	
	
	sei();
	
	TMU_Cfg_s TMU_cfg1 ;
	TMU_cfg1.Timer_channel = TMU_TIMER_CH2 ;
	TMU_cfg1.TMU_Reselution = reselution_one_mili ;
	
	TMU_Init(&TMU_cfg1);
	
	TMU_tsak_s TMU_task1 ;
	TMU_task1.delay_time = 1000;
	TMU_task1.Ptr_FunctionCall = toggle1;
	TMU_task1.Task_ID = 1;
	TMU_task1.TMU_mode = PERIODIC ;
	
	TMU_Start_Timer(&TMU_task1) ;
	
	TMU_tsak_s TMU_task2 ;
	TMU_task2.delay_time = 500;
	TMU_task2.Ptr_FunctionCall = toggle2;
	TMU_task2.Task_ID = 2;
	TMU_task2.TMU_mode = PERIODIC ;
	
	TMU_Start_Timer(&TMU_task2) ;
	
    while (1) 
    {
		TMU_Dispatch();
    }
	
	
}
