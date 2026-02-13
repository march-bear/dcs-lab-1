#include "mybuf.h"

void my_buf_init(my_buf* buf) {
    buf->write_idx = 0;
    buf->read_idx = 0;
}

bool my_buf_write(my_buf* buf, morse data) {
    if (buf->write_idx == MY_BUFFER_SIZE) {
    	return false;
    }

    buf->buffer[buf->write_idx] = data;
    buf->write_idx++;

    return true;
}

bool my_buf_next(my_buf* buf, morse* data) {
    if (buf->read_idx == buf->write_idx) {
    	return false;
    }

    *data = buf->buffer[buf->read_idx];
    buf->read_idx++;

    return true;
}

bool my_buf_curr(my_buf* buf, morse* data) {
    if (buf->read_idx == buf->write_idx) {
    	return false;
    }

    *data = buf->buffer[buf->read_idx];

    return true;
}

void my_buf_reset(my_buf* buf) {
	buf->write_idx = 0;
	buf->read_idx = 0;
}

bool my_buf_empty(my_buf* buf) {
	return buf->write_idx == 0;
}

bool my_buf_full(my_buf* buf) {
	return buf->write_idx == MY_BUFFER_SIZE;
}
