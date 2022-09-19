/*
 * morse.h
 *
 *  Created on: 19 sept. 2022
 *      Author: Andresitositoses
 */

#ifndef INC_MORSE_H_
#define INC_MORSE_H_

#include "stm32l4xx_hal.h"

/* Port/Pin settings */
#define GPIO_LED_PORT GPIOB
#define GPIO_LED_PIN GPIO_PIN_3

/* Signal durations settings (milliseconds) */
#define DOT_DELAY 200 // Dot duration
#define DASH_DELAY 800 // Dash duration
#define LETTER_STATE_DELAY 300 // Delay between dots and dashes
#define LETTER_END_DELAY 1000 // Delay between letters

/*
 * @brief Transmits the specified string via morse code through the delays set on each signal
 * @param string Letter sequence containing a message
 */
void morse(char* string);

void dot(int *letter_state, int *switched, int *delay);
void dash(int *letter_state, int *switched, int *delay);
void letter_end(int *letter_state, int *pos, int *delay);

// From 'a' to 'z'
void a(int *letter_state, int *pos, int *switched, int*delay);
void b(int *letter_state, int *pos, int *switched, int*delay);
void c(int *letter_state, int *pos, int *switched, int*delay);
void d(int *letter_state, int *pos, int *switched, int*delay);
void e(int *letter_state, int *pos, int *switched, int*delay);
void f(int *letter_state, int *pos, int *switched, int*delay);
void g(int *letter_state, int *pos, int *switched, int*delay);
void h(int *letter_state, int *pos, int *switched, int*delay);
void i(int *letter_state, int *pos, int *switched, int*delay);
void j(int *letter_state, int *pos, int *switched, int*delay);
void k(int *letter_state, int *pos, int *switched, int*delay);
void l(int *letter_state, int *pos, int *switched, int*delay);
void m(int *letter_state, int *pos, int *switched, int*delay);
void n(int *letter_state, int *pos, int *switched, int*delay);
void o(int *letter_state, int *pos, int *switched, int*delay);
void p(int *letter_state, int *pos, int *switched, int*delay);
void q(int *letter_state, int *pos, int *switched, int*delay);
void r(int *letter_state, int *pos, int *switched, int*delay);
void s(int *letter_state, int *pos, int *switched, int*delay);
void t(int *letter_state, int *pos, int *switched, int*delay);
void u(int *letter_state, int *pos, int *switched, int*delay);
void v(int *letter_state, int *pos, int *switched, int*delay);
void w(int *letter_state, int *pos, int *switched, int*delay);
void x(int *letter_state, int *pos, int *switched, int*delay);
void y(int *letter_state, int *pos, int *switched, int*delay);
void z(int *letter_state, int *pos, int *switched, int*delay);

#endif /* INC_MORSE_H_ */
