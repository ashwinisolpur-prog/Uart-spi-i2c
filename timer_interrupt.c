/*
 * timer_interrupt.c
 * Hardware Timer and Interrupt Service Routine
 * Author: Ashwini Solpure
 * Platform: ESP32 / Arduino
 * Description: Configures Timer1 in CTC mode with
 *              interrupt to trigger every 1 second
 *              without busy-wait delays
 */

#include "timer_interrupt.h"

/* Global counter incremented by ISR */
volatile unsigned int timer_count = 0;
volatile unsigned char timer_flag  = 0;

/* -----------------------------------------------
 * Timer1 Initialization
 * Mode : CTC (Clear Timer on Compare Match)
 * Prescaler: 1024
 * Compare Value: for 1 second interval at 16MHz
 * ----------------------------------------------- */
void Timer1_Init(void) {
    /* Set CTC mode (WGM12 = 1) */
    TCCR1B |= (1 << WGM12);

    /* Set prescaler to 1024 */
    TCCR1B |= (1 << CS12) | (1 << CS10);

    /* Set compare match value for 1 second */
    OCR1A = 15624;

    /* Enable Timer1 Compare Match A interrupt */
    TIMSK1 |= (1 << OCIE1A);

    /* Enable global interrupts */
    sei();
}

/* -----------------------------------------------
 * Timer1 Compare Match A - Interrupt Service Routine
 * Triggered every 1 second
 * ----------------------------------------------- */
ISR(TIMER1_COMPA_vect) {
    timer_count++;
    timer_flag = 1;
}

/* -----------------------------------------------
 * Check if 1 second has elapsed
 * Returns: 1 if elapsed, 0 otherwise
 * Clears the flag after reading
 * ----------------------------------------------- */
unsigned char Timer_IsElapsed(void) {
    if (timer_flag) {
        timer_flag = 0;
        return 1;
    }
    return 0;
}

/* -----------------------------------------------
 * Get total elapsed seconds since Timer start
 * ----------------------------------------------- */
unsigned int Timer_GetCount(void) {
    return timer_count;
}

/* -----------------------------------------------
 * Reset timer counter to zero
 * ----------------------------------------------- */
void Timer_Reset(void) {
    timer_count = 0;
}
