#include <pru/io.h>

static void delay_us(unsigned int us)
{
	/* assume cpu frequency is 200MHz */
	__delay_cycles (us * (1000 / 5));
}

const unsigned int period_us = 250 * 1000;

int main(void)
{
	unsigned int c;

	for (c = 0; ; c++) {
		__R30 = c & 1 ? 0xffff : 0x0000;
		delay_us (period_us);
	}

	return 0;
}
