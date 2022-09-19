/*
 * morse.c
 *
 *  Created on: 19 sept. 2022
 *      Author: Andresitositoses
 */

#include "morse.h"

void morse(char* string){

	HAL_GPIO_WritePin(GPIO_LED_PORT, GPIO_LED_PIN, GPIO_PIN_RESET);

	int switched = 0;
	int letter_state = 1;
	int pos = -1;

	int delay = 1000;
	int loop_end = 1;

	if(string != NULL){
		letter_state = 1;
		pos++;
		loop_end = 0;
	}

	while(!loop_end) {
		switch(string[pos]){
			case ' ':
				letter_end(&letter_state, &pos, &delay);
				break;
			case 'a':
				a(&letter_state, &pos, &switched, &delay);
				break;
			case 'b':
				b(&letter_state, &pos, &switched, &delay);
				break;
			case 'c':
				c(&letter_state, &pos, &switched, &delay);
				break;
			case 'd':
				d(&letter_state, &pos, &switched, &delay);
				break;
			case 'e':
				e(&letter_state, &pos, &switched, &delay);
				break;
			case 'f':
				f(&letter_state, &pos, &switched, &delay);
				break;
			case 'g':
				g(&letter_state, &pos, &switched, &delay);
				break;
			case 'h':
				h(&letter_state, &pos, &switched, &delay);
				break;
			case 'i':
				i(&letter_state, &pos, &switched, &delay);
				break;
			case 'j':
				j(&letter_state, &pos, &switched, &delay);
				break;
			case 'k':
				k(&letter_state, &pos, &switched, &delay);
				break;
			case 'l':
				l(&letter_state, &pos, &switched, &delay);
				break;
			case 'm':
				m(&letter_state, &pos, &switched, &delay);
				break;
			case 'n':
				n(&letter_state, &pos, &switched, &delay);
				break;
			case 'o':
				o(&letter_state, &pos, &switched, &delay);
				break;
			case 'p':
				p(&letter_state, &pos, &switched, &delay);
				break;
			case 'q':
				q(&letter_state, &pos, &switched, &delay);
				break;
			case 'r':
				r(&letter_state, &pos, &switched, &delay);
				break;
			case 's':
				s(&letter_state, &pos, &switched, &delay);
				break;
			case 't':
				t(&letter_state, &pos, &switched, &delay);
				break;
			case 'u':
				u(&letter_state, &pos, &switched, &delay);
				break;
			case 'v':
				v(&letter_state, &pos, &switched, &delay);
				break;
			case 'w':
				w(&letter_state, &pos, &switched, &delay);
				break;
			case 'x':
				x(&letter_state, &pos, &switched, &delay);
				break;
			case 'y':
				y(&letter_state, &pos, &switched, &delay);
				break;
			case 'z':
				z(&letter_state, &pos, &switched, &delay);
				break;
			default:
				loop_end = 1;
				break;
		}

		HAL_Delay(delay);
	}
}

void dot(int *letter_state, int *switched, int *delay){
	if(!*switched){
		HAL_GPIO_WritePin(GPIO_LED_PORT, GPIO_LED_PIN, GPIO_PIN_SET);
		*delay = DOT_DELAY;
		*switched = 1;
	}
	else{
		HAL_GPIO_WritePin(GPIO_LED_PORT, GPIO_LED_PIN, GPIO_PIN_RESET);
		*delay = LETTER_STATE_DELAY;
		*switched = 0;
		*letter_state += 1;
	}
}

void dash(int *letter_state, int *switched, int *delay){
    if(!*switched){
        HAL_GPIO_WritePin(GPIO_LED_PORT, GPIO_LED_PIN, GPIO_PIN_SET);
        *delay = DASH_DELAY;
        *switched = 1;
    }
    else{
        HAL_GPIO_WritePin(GPIO_LED_PORT, GPIO_LED_PIN, GPIO_PIN_RESET);
        *delay = LETTER_STATE_DELAY;
        *switched = 0;
        *letter_state += 1;
    }
}

void letter_end(int *letter_state, int *pos, int *delay){
    *delay = LETTER_END_DELAY;
    *letter_state = 1;
    *pos += 1;
}

void a(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dot(letter_state, switched, delay);
            break;
        case 2:
            dash(letter_state, switched, delay);
            break;
        case 3:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void b(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dash(letter_state, switched, delay);
            break;
        case 2:
            dot(letter_state, switched, delay);
            break;
        case 3:
            dot(letter_state, switched, delay);
            break;
        case 4:
            dot(letter_state, switched, delay);
            break;
        case 5:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void c(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dash(letter_state, switched, delay);
            break;
        case 2:
            dot(letter_state, switched, delay);
            break;
        case 3:
            dash(letter_state, switched, delay);
            break;
        case 4:
            dot(letter_state, switched, delay);
            break;
        case 5:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void d(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dash(letter_state, switched, delay);
            break;
        case 2:
            dot(letter_state, switched, delay);
            break;
        case 3:
            dot(letter_state, switched, delay);
            break;
        case 4:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void e(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dot(letter_state, switched, delay);
            break;
        case 2:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void f(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dot(letter_state, switched, delay);
            break;
        case 2:
            dot(letter_state, switched, delay);
            break;
        case 3:
            dash(letter_state, switched, delay);
            break;
        case 4:
            dot(letter_state, switched, delay);
            break;
        case 5:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void g(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dash(letter_state, switched, delay);
            break;
        case 2:
            dash(letter_state, switched, delay);
            break;
        case 3:
            dot(letter_state, switched, delay);
            break;
        case 4:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void h(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dot(letter_state, switched, delay);
            break;
        case 2:
            dot(letter_state, switched, delay);
            break;
        case 3:
            dot(letter_state, switched, delay);
            break;
        case 4:
            dot(letter_state, switched, delay);
            break;
        case 5:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void i(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dot(letter_state, switched, delay);
            break;
        case 2:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void j(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dot(letter_state, switched, delay);
            break;
        case 2:
            dash(letter_state, switched, delay);
            break;
        case 3:
            dash(letter_state, switched, delay);
            break;
        case 4:
            dash(letter_state, switched, delay);
            break;
        case 5:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void k(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dash(letter_state, switched, delay);
            break;
        case 2:
            dot(letter_state, switched, delay);
            break;
        case 3:
            dash(letter_state, switched, delay);
            break;
        case 4:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void l(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dot(letter_state, switched, delay);
            break;
        case 2:
            dash(letter_state, switched, delay);
            break;
        case 3:
            dot(letter_state, switched, delay);
            break;
        case 4:
            dot(letter_state, switched, delay);
            break;
        case 5:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void m(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dash(letter_state, switched, delay);
            break;
        case 2:
            dash(letter_state, switched, delay);
            break;
        case 3:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void n(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dash(letter_state, switched, delay);
            break;
        case 2:
            dot(letter_state, switched, delay);
            break;
        case 3:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void o(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dash(letter_state, switched, delay);
            break;
        case 2:
            dash(letter_state, switched, delay);
            break;
        case 3:
            dash(letter_state, switched, delay);
            break;
        case 4:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void p(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dot(letter_state, switched, delay);
            break;
        case 2:
            dash(letter_state, switched, delay);
            break;
        case 3:
            dash(letter_state, switched, delay);
            break;
        case 4:
            dot(letter_state, switched, delay);
            break;
        case 5:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void q(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dash(letter_state, switched, delay);
            break;
        case 2:
            dash(letter_state, switched, delay);
            break;
        case 3:
            dot(letter_state, switched, delay);
            break;
        case 4:
            dash(letter_state, switched, delay);
            break;
        case 5:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void r(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dot(letter_state, switched, delay);
            break;
        case 2:
            dash(letter_state, switched, delay);
            break;
        case 3:
            dot(letter_state, switched, delay);
            break;
        case 4:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void s(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dot(letter_state, switched, delay);
            break;
        case 2:
            dot(letter_state, switched, delay);
            break;
        case 3:
            dot(letter_state, switched, delay);
            break;
        case 4:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void t(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dash(letter_state, switched, delay);
            break;
        case 2:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void u(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dot(letter_state, switched, delay);
            break;
        case 2:
            dot(letter_state, switched, delay);
            break;
        case 3:
            dash(letter_state, switched, delay);
            break;
        case 4:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void v(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dot(letter_state, switched, delay);
            break;
        case 2:
            dot(letter_state, switched, delay);
            break;
        case 3:
            dot(letter_state, switched, delay);
            break;
        case 4:
            dash(letter_state, switched, delay);
            break;
        case 5:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void w(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dot(letter_state, switched, delay);
            break;
        case 2:
            dash(letter_state, switched, delay);
            break;
        case 3:
            dash(letter_state, switched, delay);
            break;
        case 4:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void x(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dash(letter_state, switched, delay);
            break;
        case 2:
            dot(letter_state, switched, delay);
            break;
        case 3:
            dot(letter_state, switched, delay);
            break;
        case 4:
            dash(letter_state, switched, delay);
            break;
        case 5:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void y(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dash(letter_state, switched, delay);
            break;
        case 2:
            dot(letter_state, switched, delay);
            break;
        case 3:
            dash(letter_state, switched, delay);
            break;
        case 4:
            dash(letter_state, switched, delay);
            break;
        case 5:
            letter_end(letter_state, pos, delay);
            break;
    }
}

void z(int *letter_state, int *pos, int *switched, int*delay){
    switch(*letter_state){
        case 1:
            dash(letter_state, switched, delay);
            break;
        case 2:
            dash(letter_state, switched, delay);
            break;
        case 3:
            dot(letter_state, switched, delay);
            break;
        case 4:
            dot(letter_state, switched, delay);
            break;
        case 5:
            letter_end(letter_state, pos, delay);
            break;
    }
}
