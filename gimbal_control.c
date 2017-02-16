#include <stm32f4xx.h>

int main(void){
	
	unsigned long int count = 1000000;

	RCC->AHB1ENR |= 0x7; //Turn on GPIO clock for ports A, B, and C
	
	GPIOA->MODER |= 0x540440; //3-EN3, 5-EN1, 9-IN2, 10-IN3, 11-IN1
	GPIOB->MODER |= 0x140000; //LED output and 10-EN2
	GPIOC->MODER |= 0x14; //nSLEEP and nRESET outputs
	
	GPIOB->ODR |= 0x200; //Turn on LED
	GPIOC->ODR |= 0x2;//Turn off sleep mode
	
	//RCC->CR |= 0x10000;
	
	while(count > 0) count--;
	count = 400000;
	
	//RCC->CFGR |= 0x1; //Switch clock source
	GPIOC->ODR |= 0x4; //Enable
	
	while(count > 0) count--;
	count = 500000;

	
	//These states provide a sine wave to the three-phase motor by 
	//selectively enabling and disabling the motor driver outputs
	while(1){

		//state 1
		while(count > 0) count--;
		count = 10000;
		GPIOA->ODR = 0x820;
		GPIOB->ODR = 0x400;
		
		//state 2
		while(count > 0) count--;
		count = 10000;
		GPIOA->ODR = 0x828;
		GPIOB->ODR = 0x0;
		
		//state 3
		while(count > 0) count--;
		count = 10000;
		GPIOA->ODR = 0xa08;
		GPIOB->ODR = 0x400;
		
		//state 4
		while(count > 0) count--;
		count = 10000;
		GPIOA->ODR = 0x620;
		GPIOB->ODR = 0x400;
		
		//state 5
		while(count > 0) count--;
		count = 10000;
		GPIOA->ODR = 0x628;
		GPIOB->ODR = 0x0;
		
		//state 6
		while(count > 0) count--;
		count = 10000;
		GPIOA->ODR = 0x408;
		GPIOB->ODR = 0x400;
		
	}
}
