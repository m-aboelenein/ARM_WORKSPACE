

#include "stm32f4xx.h"

// Create a function to wait for a specific amount of time

int main(void)
{
	// Enable the GPIO clock for port A using RCC and AHB
    RCC ->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    // or RCC ->AHB1ENR |= (1<<19)

	// set any registers to control port A pin 5
	// MODER
    GPIOA ->MODER |= GPIO_MODER_MODER5_0 ;
	// OTYPER

	//OSPEEDR

	//PUPDR


  int i = 0;


  while (1){
	  //turn on LED using BRR
	  //wait
	  //turn off lED using BRR


	i++;

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
