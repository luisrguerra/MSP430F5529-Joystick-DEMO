#include <msp430.h>
#include <joystick.h>
#include <stdio.h> //printf()
//Change "Heap Size" to 320 to text show on terminal
//Project -> Properties -> Build -> MSP430 Linker -> Basic Options

//MSP-430-EXP430F5529LP
//Used: Joystick ky-023
//GND -> GND (Ground)
//+5V -> 5V
//URX -> P6.0
//URY -> P6.1

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

	// Joystick
	volatile uint16_t xAxis = 0;
	volatile uint16_t yAxis = 0;
	joystickSetup();

	while(1){
	    joystickRead(& xAxis, & yAxis);
	    printf("-----------\n");
	    printf("X Axis: ");
	    printf("%d\n",xAxis);
	    printf("Y Axis: ");
	    printf("%d\n",yAxis);

	    const int maxValue = 4095;
	    const int minimumValue = 0;
	    const int minimumMargin = minimumValue + 230;
	    const int maxMargin = maxValue - 40;
	    if (yAxis < minimumMargin && xAxis < maxValue){
	        printf("Up\n");
	    }
	    else if (yAxis >= maxMargin && xAxis >= maxMargin){
	        printf("Down\n");
	    }
	    else if (yAxis > minimumMargin && xAxis < minimumMargin){
	         printf("Right\n");
	    }
	    else if (yAxis < maxMargin && xAxis >= maxMargin){
	        printf("Left\n");
	    }
	}

	return 0;
}
