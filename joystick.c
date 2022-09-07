#include <msp430.h>
#include "joystick.h"

void joystickSetup() {
    ADC12CTL0 = ~ADC12ENC;          // Desabilita conversoes

    P6SEL |= (BIT0 | BIT1);         // Enable P6.0 e P6.1

    ADC12CTL0 = ADC12SHT0_3 |       // 32 ADC12CLK cycles
                ADC12MSC    |       // Multiple sample
                ADC12ON;            // Liga AD

    ADC12CTL1 = ADC12SHP      |     // Sampling timer
                ADC12CONSEQ_1;      // Sequencia de canais

    ADC12CTL2 = ADC12TCOFF |        // Desliga sensor de temperatura
                ADC12RES_2;

    ADC12MCTL1 = ADC12EOS  |        // End of sequence
                 ADC12INCH_1;       // Canal A1

    ADC12IFG = 0;

    ADC12CTL0 |= ADC12ENC;          // Habilita conversoes
}

void joystickRead(uint16_t *xAxis, uint16_t *yAxis) {
    ADC12CTL0 &= ~ADC12SC;                  // Gera um pulso para
    ADC12CTL0 |=  ADC12SC;                  // iniciar a conversao

    while(!(ADC12IFG & ADC12IFG1));

    *yAxis = ADC12MEM0;
    *xAxis = ADC12MEM1;
}
