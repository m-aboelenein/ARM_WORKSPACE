
#include "stm32f4xx.h"


int main(void)
{

	RCC ->APB2ENR |= RCC_APB2ENR_TIM1EN; // Enable Clock for TIMER 1
    TIM1 -> PSC =10000;  // SET PRESCALLER TO 10000
    TIM1 -> CR1 |= TIM_CR1_CEN; // Enable Timer 1
    TIM1 -> CR1 |= TIM_CR1_DIR; // Set the Direction to Down Counter
    TIM1 -> ARR = 1000;   // Set overflow register to 1000


  while (1)
  {

  }
}
