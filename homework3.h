/*
 * homework3.h
 *
 *  Created on:
 *      Author:
 */



#ifndef HOMEWORK3_H_
#define HOMEWORK3_H_

typedef enum {Off, Red, Green, Yellow, Blue, Magenta, Cyan, White} color;
typedef enum {Pressed, Released} ButtonState;
typedef enum {Pressed_S, RTransition, Released_S, Ptransition} debounce_state;
typedef struct
{
    uint_fast8_t Port; // port for button
    uint_fast16_t Pin;
    debounce_state Debounce_state;
    ButtonState Current_State;
    uint32_t Timer; // the debouncing timer
} button;


bool button_pushed(button *b);

// This function initializes the board by turning off the Watchdog Timer.
void initBoard();
// This function indexes a count value to an LED color on Launchpad LED2.
void changeLaunchpadLED2(color currentColor);
// This function indexes a count value to an LED color on the Boosterpack LED.
void changeBoosterpackLED(color BLEDColor);
// This function serves as a debounce state machine for Boosterpack button S1
color updateColor(color currentColor);

bool fsmBoosterpackButtonS1(unsigned int buttonhistory);


// TODO: Define any constants that are local to homework.c using #define


#endif /* HOMEWORK3_H_ */
