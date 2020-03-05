#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned char buttonhistory;

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
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c

        if (timer0Expired()) //check to see if the timer has expierd return true when it does.
            count0++;

        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if (timer1Expired() ) //check to see if the timer has expierd return true when it does.
         buttonhistory=checkStatus_BoosterpackS1();


        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        if(fsmBoosterpackButtonS1(buttonhistory))


        // TODO: If a completed, debounced button press has occurred, increment count1.
        count1++;


    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{


    if (~((count|BIT2) & (count|BIT1) & (count|BIT0)))
    {
       // count = 0;
        turnOff_LaunchpadLED2Red();
                turnOff_LaunchpadLED2Green();
                turnOff_LaunchpadLED2Blue();
    }
    else  if(~(count|BIT2) & ~(count|BIT1) & (count|BIT0))
    {
      //  count = 1;
        turnOn_LaunchpadLED2Red();
    }
    else if(~(count|BIT2) & (count|BIT1) &~ (count|BIT0))
     {
         //count = 2;
         turnOff_LaunchpadLED2Red();
         turnOn_LaunchpadLED2Green();
     }
    else  if(~(count|BIT2) & (count|BIT1) & (count|BIT0))
         {
            // count = 3;
        turnOff_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Blue();
         }
    else if((count|BIT2) & ~(count|BIT1) &~ (count|BIT0))
         {
         //    count = 4;
         }
    else if((count|BIT2) & ~(count|BIT1) & (count|BIT0))
         {
           //  count = 5;
         }
    else   if((count|BIT2) & (count|BIT1) &~ (count|BIT0))
         {
          //   count = 6;
         }
    else  if((count|BIT2) & (count|BIT1) & (count|BIT0))
         {
         //    count = 7;
         }

 /*   switch (count)
    {
    case 0:
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
        break;
    case 1:
        turnOn_LaunchpadLED2Red();

        break;
    case 2:
        turnOn_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Red();
        break;
    case 3:
        turnOff_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Blue();
        break;
    case 4:
        turnOff_LaunchpadLED2Green();
        break;
    case 5:
        turnOn_LaunchpadLED2Red();

        break;
    case 6:
        turnOff_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        break;
    case 7:
        turnOn_LaunchpadLED2Red();

        break;
    }*/
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{

}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned int buttonhistory)
{
    bool pressed = false;


    return pressed;
}
