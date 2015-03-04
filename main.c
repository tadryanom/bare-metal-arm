#include "MKL46Z4.h"

#define LED_GREEN_ENABLE 1

void delay(void)
{
	int i;

	for (i = 0; i < 1000000; i++);
}

#if LED_GREEN_ENABLE
void led_green_init()
{
	SIM_COPC = 0;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	PORTD_PCR5 = PORT_PCR_MUX(1);
	GPIOD_PDDR |= (1 << 5);
	GPIOD_PSOR = (1 << 5);
}

void led_green_toggle()
{
	GPIOD_PTOR = (1 << 5);
}
#endif

#if LED_RED_ENABLE
void led_red_init()
{
	SIM_COPC = 0;
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
	PORTE_PCR29 = PORT_PCR_MUX(1);
	GPIOE_PDDR |= (1 << 29);
	GPIOE_PSOR = (1 << 29);
}

void led_red_toggle(void)
{
	GPIOE_PTOR = (1 << 29);
}
#endif

void main(void)
{
	led_green_init();

	while (1) {
		led_green_toggle();
		delay();
	}
}
