#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "Vector.h"

void vector_init(vector *vec) {
    vec->cap = VECTOR_INIT_CAPACITY;
    vec->size = 0;
    vec->items = malloc(sizeof(point) * vec->cap);
}

int vector_total(vector *vec) {
    return vec->size;
}

static void vector_resize(vector *vec, int cap) {
#ifdef DEBUG_ON
    printf("vector_resize: %d to %d\n", vec->cap, cap);
#endif

    point *items = realloc(vec->items, sizeof(void *) * cap);
    if (items) {
        vec->items = items;
        vec->cap = cap;
    }
}

void vector_add(vector *vec, point *item) {
    if (vec->cap == vec->size)
        vector_resize(vec, vec->cap * 2);
    vec->items[vec->size++] = *item;
}

void vector_set(vector *vec, int idx, point *item) {
    if (idx >= 0 && idx < vec->size)
        vec->items[idx] = *item;
}

void vector_insert(vector *vec, int idx, point *item) {
    if (idx < 0 || idx > vec->size)
        return;
    if (vec->size == vec->cap)
        vector_resize(vec, vec->cap * 2);
    for (int i = vec->size; i >= idx; i--) {
        vec->items[i + 1] = vec->items[i];
    }
    vec->items[idx] = *item;
    vec->size++;
}

point *vector_get(vector *vec, int idx) {
    if (idx >= 0 && idx < vec->size)
        return &(vec->items[idx]);
    return NULL;
}

void vector_delete(vector *vec, int idx) {
    if (idx < 0 || idx > vec->size)
        return;
    for (int i = idx; i < vec->size - 1; i++) {
        vec->items[i] = vec->items[i + 1];
    }
    vec->size--;
    if (vec->size > 0 && vec->size == vec->cap / 4)
        vector_resize(vec, vec->cap / 2);
}

void vector_free(vector *vec) {
    free(vec->items);
}

void vector_copy(vector *src, vector *dst) {
    point *tmp_items = malloc(sizeof(point) * src->cap);
    for(int i = 0; i<src->cap; i++){
        tmp_items[i] = src->items[i];
    }
    vector_init(dst);
    dst->items = tmp_items;
    dst->cap = src->cap;
    dst->size = src->size;
}
