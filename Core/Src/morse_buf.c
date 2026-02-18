#include "morse_buf.h"

bool morse_buf_write(morse_buf* buf, morse data) {
    if (buf->write_idx == MORSE_BUFFER_SIZE) {
    	return false;
    }

    buf->buffer[buf->write_idx] = data;
    buf->write_idx++;

    return true;
}

bool morse_buf_next(morse_buf* buf, morse* data) {
    if (buf->read_idx == buf->write_idx) {
    	return false;
    }

    *data = buf->buffer[buf->read_idx];
    buf->read_idx++;

    return true;
}

bool morse_buf_curr(morse_buf* buf, morse* data) {
    if (buf->read_idx == buf->write_idx) {
    	return false;
    }

    *data = buf->buffer[buf->read_idx];

    return true;
}

void morse_buf_reset(morse_buf* buf) {
	buf->write_idx = 0;
	buf->read_idx = 0;
}

bool morse_buf_empty(morse_buf* buf) {
	return buf->write_idx == 0;
}

bool morse_buf_full(morse_buf* buf) {
	return buf->write_idx == MORSE_BUFFER_SIZE;
}
