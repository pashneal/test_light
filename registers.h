volatile register unsigned int __R30;
volatile register unsigned int __R31;
void static inline set_reg30(unsigned int value ){ __R30 = value; }
void static inline or_reg30(unsigned int value ){ __R30 |= value; }
void static inline xor_reg30(unsigned int value ){ __R30 ^= value; }
void static inline and_reg30(unsigned int value ){ __R30 &= value; }
void sleep(unsigned int value){ while (value--) __delay_cycles(200000); } 
