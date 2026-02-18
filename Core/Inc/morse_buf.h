#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "morse.h"

#define MORSE_BUFFER_SIZE 8

typedef struct {
    morse buffer[MORSE_BUFFER_SIZE];
    uint16_t write_idx;
    uint16_t read_idx;
} morse_buf;

bool morse_buf_write(morse_buf* buf, morse data);
bool morse_buf_next(morse_buf* buf, morse* data);
void morse_buf_reset(morse_buf* buf);
bool morse_buf_curr(morse_buf* buf, morse* data);
bool morse_buf_empty(morse_buf* buf);
bool morse_buf_full(morse_buf* buf);
