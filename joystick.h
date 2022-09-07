#ifndef _ADC_H
#define _ADC_H

#include <stdint.h> //uint16_t

void joystickSetup();
void joystickRead(uint16_t *xAxis, uint16_t *yAxis);

#endif // _ADC_H
