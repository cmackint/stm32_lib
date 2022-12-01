#ifndef CIRCBUF_H
#define CIRCBUF_H

#include <stdint.h>
#include <stdio.h>

typedef struct {
    size_t head;
    size_t tail;
    uint8_t *data;
    size_t len;
} CircBuf;

int CircBuf_init(CircBuf *circBuf, uint8_t *data, size_t len) {
    if (data == NULL || len == 0) {
        return -1;
    }

    circBuf->head = 0;
    circBuf->tail = 0;
    circBuf->data = data;
    circBuf->len = len;
}

void circBuf_reset(CircBuf *circBuf) {
    circBuf->head = 0;
    circBuf->tail = 0;
}

int CircBuf_write(CircBuf *circBuf, uint8_t *data, size_t len) {
    int overwriteOccured = 0;

    for (size_t i = 0; i < len; i++) {
        circBuf->data[circBuf->head] = data[i];

        circBuf->head = (circBuf->head == circBuf->len - 1) ? 0 : circBuf->head + 1;

        if (circBuf->head == circBuf->tail) {
            overwriteOccured = -1;
        }
    }

    return overwriteOccured;
}

int CircBuf_read(CircBuf *circBuf, uint8_t *data) {
    if (circBuf->tail == circBuf->head) {
        return -1; // No data
    }

    *data = circBuf->data[circBuf->tail];

    circBuf->tail = (circBuf->tail == circBuf->len - 1) ? 0 : circBuf->tail + 1;

    return 0;
}

#endif // CIRCBUF_H
