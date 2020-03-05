#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"




int main(void)
{


  // unsigned int count1 = 0; //Given by teacher i didnt understand its usecase.

    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned char buttonhistory;
    // Count variables to control the LEDs. Which come from the same typedef enum for the switch case statements below.
    color currentColor = Off;
    color BLEDColor = Off;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER0, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER1, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(currentColor);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(BLEDColor);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c

        if (timer0Expired()) //check to see if the timer has expirerd return true when it does.
            currentColor = updateColor(currentColor);

        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if (timer1Expired()) //check to see if the timer has expirerd return true when it does.
            BLEDColor = updateColor(BLEDColor);
      //   buttonhistory=checkStatus_BoosterpackS1();


        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
       // if(fsmBoosterpackButtonS1(buttonhistory))


        // TODO: If a completed, debounced button press has occurred, increment count1.
       //count1++;
    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(color currentColor)
{
    switch (currentColor)
    {
    case Off:
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
        break;
    case Red:
        turnOn_LaunchpadLED2Red();
        break;
    case Green:
        turnOn_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Red();
        break;
    case Yellow:// red green
        turnOn_LaunchpadLED2Red();
        break;
    case Blue:
        turnOn_LaunchpadLED2Blue();
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        break;
    case Magenta://blue red
        turnOn_LaunchpadLED2Red();
        break;
    case Cyan://green blue
        turnOff_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        break;
    case White://all on
        turnOn_LaunchpadLED2Red();
        break;
    }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(color BLEDColor)
{
    switch (BLEDColor)
    {
    case Off:
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
        break;
    case Red:
        turnOn_BoosterpackLEDRed();
        break;
    case Green:
        turnOn_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDRed();
        break;
    case Yellow:// red green
        turnOn_BoosterpackLEDRed();
        break;
    case Blue:
        turnOn_BoosterpackLEDBlue();
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        break;
    case Magenta://blue red
        turnOn_BoosterpackLEDRed();
        break;
    case Cyan://green blue
        turnOff_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        break;
    case White://all on
        turnOn_BoosterpackLEDRed();
        break;
    }
}


// this will update the color that will come NEXT when the typedef color is at a current case.
color updateColor(color currentColor)
{
    color newColor;
    switch (currentColor)
        {
        case Off:
            newColor = Red;
            break;
        case Red:
            newColor = Green;
            break;
        case Green:
            newColor = Yellow;
            break;
        case Yellow:
            newColor = Blue;
            break;
        case Blue:
            newColor = Magenta;
            break;
        case Magenta:
            newColor = Cyan;
            break;
        case Cyan:
            newColor = White;
            break;
        case White:
            newColor = Off;
            break;
        }
    return newColor;
}


// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned int buttonhistory)
{
    bool pressed = false;


    return pressed;
}
