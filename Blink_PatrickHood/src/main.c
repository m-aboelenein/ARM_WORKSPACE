

#include "stm32f4xx.h"

//function to Delay for a specific amount of time
void DELAY(int delay_time)
{

	volatile int i,j ;

	for(i=0;i<delay_time;i++) {
		j++;
	}
}



int main(void)
{
	// Enable the GPIO clock for port A using RCC and AHB
	RCC ->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    // or RCC ->AHB1ENR |= (1<<19)

	/*
	 *  set any registers to control port A pin 5
	 *  x    11
	 *  x_0  01
	 *  x_1  10

   */
    GPIOA ->MODER |= GPIO_MODER_MODER5_0 ; // OUTPUT MODE
    GPIOA ->MODER &= ~(GPIO_MODER_MODER5_1) ;
    /* to ensure the left bit is a zero and not affected by another operation
       so the OR can work Correctly
    */
    GPIOA ->OTYPER &=~(GPIO_OTYPER_OT_5); // PUSH PULL MODE
    GPIOA ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5; //HIGH SPEED MODE
    GPIOA ->PUPDR &=~ (GPIO_PUPDR_PUPDR5);  // None (NOPUPD)



  while (1)
  {
	  //turn on LED using BSRR
	  GPIOA->BSRRL |= (1<<5);
	  //wait
	  DELAY(200000);
	  //turn off lED using BSRR
	  GPIOA->BSRRH |= (1<<5);
	  DELAY(200000);

  }
}















/**
  *  IMPORTANT NOTE!
  *  The symbol VECT_TAB_SRAM needs to be defined when building the project
  *  if code has been located to RAM and interrupts are used. 
  *  Otherwise the interrupt table located in flash will be used.
  *  See also the <system_*.c> file and how the SystemInit() function updates 
  *  SCB->VTOR register.  
  *  E.g.  SCB->VTOR = 0x20000000;  
  */

  /* TODO - Add your application code here */

  /* Infinite loop */
