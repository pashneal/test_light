volatile register unsigned int __R30;
volatile register unsigned int __R31;
void set_reg30(unsigned int value ){ __R30 = value; }
void or_reg30(unsigned int value ){ __R30 |= value; }
void xor_reg30(unsigned int value ){ __R30 ^= value; }
void and_reg30(unsigned int value ){ __R30 &= value; }
void sleep(unsigned int value){ while (value--) __delay_cycles(200000); } 
