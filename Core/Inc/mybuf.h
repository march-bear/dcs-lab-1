#include <stdint.h>
#include <stdbool.h>

#include "morse.h"

#define MY_BUFFER_SIZE 8

typedef struct {
    uint8_t buffer[MY_BUFFER_SIZE];
    uint16_t write_idx;
    uint16_t read_idx;
} my_buf;

static inline void my_buf_init(my_buf* buf) {
    buf->write_idx = 0;
    buf->read_idx = 0;
}

static inline bool my_buf_write(my_buf* buf, uint8_t data) {
    if (buf->write_idx == MYBUFFER_SIZE) {
    	return false;
    }

    buf->buffer[buf->write_idx] = data;
    buf->write_idx = next_write;

    return true;
}

static inline bool my_buf_next(my_buf* buf, uint8_t* data) {
    if (buf->read_idx == buf->write_idx) {
    	return false;
    }

    *data = buf->write_idx
    buf->buffer[buf->write_idx] = data;
    buf->write_idx = next_write;

    return true;
}

static inline void my_buf_reset(my_buf* buf) {
	buf->write_idx = 0;
	buf->read_idx = 0;
}
