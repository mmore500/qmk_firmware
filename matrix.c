/*
 * scan matrix
 */
#include <avr/io.h>
#include <util/delay.h>
#include "keymap.h"
#include "matrix.h"
#include "print.h"

uint8_t *matrix;
uint8_t *prev_matrix;
static uint8_t _matrix0[MATRIX_ROWS];
static uint8_t _matrix1[MATRIX_ROWS];

static uint8_t read_col(void);
static void select_row(uint8_t row);


void matrix_init(void)
{
    // Column: input w/pullup
    DDRB = 0x00;
    PORTB = 0xFF;

    // Row: Hi-Z(unselected)
    // PD:0,1,2,3,6,7
    // PC:6,7
    // PF:7
    DDRD = 0x00;
    PORTD = 0x00;
    DDRC = 0x00;
    PORTC = 0x00;
    DDRF = 0x00;
    PORTF = 0x00;

    for (int i=0; i < MATRIX_ROWS; i++) {
        _matrix0[i] = 0xFF;
        _matrix1[i] = 0xFF;
    }
    matrix = _matrix0;
    prev_matrix = _matrix1;
}

uint8_t matrix_scan(void)
{
    uint8_t row, state;
    uint8_t *tmp;

    tmp = prev_matrix;
    prev_matrix = matrix;
    matrix = tmp;

    for (row = 0; row < MATRIX_ROWS; row++) {
        select_row(row);
        _delay_us(30);  // without this wait read unstable value.
        state = read_col();

        matrix[row] = state;
    }
    return 1;
}

static uint8_t read_col(void)
{
    return PINB;
}

static void select_row(uint8_t row)
{
    switch (row) {
        case 0:
            DDRD  = (1<<0);
            PORTD = 0x00;
            DDRC  = 0x00;
            PORTC = 0x00;
            DDRF  = 0x00;
            PORTF = 0x00;
            break;
        case 1:
            DDRD  = (1<<1);
            PORTD = 0x00;
            DDRC  = 0x00;
            PORTC = 0x00;
            DDRF  = 0x00;
            PORTF = 0x00;
            break;
        case 2:
            DDRD  = (1<<2);
            PORTD = 0x00;
            DDRC  = 0x00;
            PORTC = 0x00;
            DDRF  = 0x00;
            PORTF = 0x00;
            break;
        case 3:
            DDRD  = (1<<3);
            PORTD = 0x00;
            DDRC  = 0x00;
            PORTC = 0x00;
            DDRF  = 0x00;
            PORTF = 0x00;
            break;
        case 4:
            DDRD  = (1<<6);
            PORTD = 0x00;
            DDRC  = 0x00;
            PORTC = 0x00;
            DDRF  = 0x00;
            PORTF = 0x00;
            break;
        case 5:
            DDRD  = (1<<7);
            PORTD = 0x00;
            DDRC  = 0x00;
            PORTC = 0x00;
            DDRF  = 0x00;
            PORTF = 0x00;
            break;
        case 6:
            DDRD  = 0x00;
            PORTD = 0x00;
            DDRC  = (1<<6);
            PORTC = 0x00;
            DDRF  = 0x00;
            PORTF = 0x00;
            break;
        case 7:
            DDRD  = 0x00;
            PORTD = 0x00;
            DDRC  = (1<<7);
            PORTC = 0x00;
            DDRF  = 0x00;
            PORTF = 0x00;
            break;
        case 8:
            DDRD  = 0x00;
            PORTD = 0x00;
            DDRC  = 0x00;
            PORTC = 0x00;
            DDRF  = (1<<7);
            PORTF = 0x00;
            break;
    }
}