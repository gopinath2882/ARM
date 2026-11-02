#include <LPC21XX.H>

void Interrupt0(void) __irq;
void Interrupt1(void) __irq;
void Interrupt2(void) __irq;
void Interrupt3(void) __irq;

// EINT0 ISR (P0.1 - Channel 14)

void Interrupt0(void) __irq
{
    EXTINT = 0x01;        // Clear EINT0 flag (bit 0)
    IOSET0 = (1 << 15);    // LED OFF
    IOCLR0 = (1 << 15);    // LED ON
    VICVectAddr = 0;      // End of ISR
}

// EINT1 ISR (P0.3 - Channel 15)
void Interrupt1(void) __irq
{
    EXTINT = 0x02;        //  Clear EINT1 flag (bit 1)
    IOSET0 = (1 << 16);    // Toggle LED
    IOCLR0 = (1 << 16);
    VICVectAddr = 0;
}

// EINT2 ISR (P0.7 - Channel 16)
void Interrupt2(void) __irq
{
    EXTINT = 0x04;        //  Clear EINT2 flag (bit 2)
    IOSET0 = (1 << 17);    // Toggle LED
    IOCLR0 = (1 << 17);
    VICVectAddr = 0;
}

// EINT3 ISR (P0.20 - Channel 17)
void Interrupt3(void) __irq
{
    EXTINT = 0x08;        //  Clear EINT3 flag (bit 3)
    IOSET0 = (1 << 18);    // Toggle LED
    IOCLR0 = (1 << 18);
    VICVectAddr = 0;
}

int main(void)
{
	  int count=0;
    // P0.1 = EINT0
    PINSEL0 |= (1 << 3)|(1 << 2);       // CORRECTED: Bits 3:2 = 1 1  for EINT0     Ensure bit 3 is 0
    
    // P0.3 = EINT1
    PINSEL0 |= (1 << 7)|(1 << 6);      // Bits 7:6 = 01 for EINT1
    
    // P0.7 = EINT2
    PINSEL0 |= (1 << 15)|(1 << 14);      // Bits 15:14 = 10 for EINT2
    
    // P0.20 = EINT3
    PINSEL1 |= (1 << 9)| (1 << 8);      // Bits 9:8 = 20 for EINT3

    IODIR0 = (1 << 14) | (1 << 15) | (1 << 16) | (1 << 17);             // P0.8 to P0.11as OUTPUT for LEDs

    VICIntSelect = 0;          // All interrupts as IRQ

    // Slot 0 = EINT0 (Channel 14)
    VICVectCntl0 = (0x20) | 14;
    VICVectAddr0 = (unsigned long) Interrupt0;

    // Slot 1 = EINT1 (Channel 15)
    VICVectCntl1 = (0x20) | 15;
    VICVectAddr1 = (unsigned long) Interrupt1;

    // Slot 2 = EINT2 (Channel 16)
    VICVectCntl2 = (0x20) | 16;
    VICVectAddr2 = (unsigned long) Interrupt2;

    // Slot 3 = EINT3 (Channel 17)
    VICVectCntl3 = (0x20) | 17;
    VICVectAddr3 = (unsigned long) Interrupt3;
   
	 /*  EXTMODE = 0x00;     Level-sensitive
    EXTPOLAR = 0x00;            Active high*/
//	------------------------------------
   /*EXTMODE = 0x00;     Level-sensiti
	 EXTPOLAR = 0x0f;    // Active high*/
//-------------------------------------
 /*    EXTMODE = 0x0f;     //edge-sensitive
    EXTPOLAR = 0x0f;    */       // rise edge 
    EXTMODE = 0x0f;     //edge-sensitive
    EXTPOLAR = 0x00;           // faling edge 


    //  Enable Interrupts 
    VICIntEnable = (1 << 14) | (1 << 15) | (1 << 16) | (1 << 17);

    while(1)
			count++;
		
}