#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"

#define VECTOR_INIT_CAPACITY 4

#define VECTOR_INIT(vec) vector vec; vector_init(&vec)
#define VECTOR_ADD(vec, item) vector_add(&vec, item)
#define VECTOR_SET(vec, idx, item) vector_set(&vec, idx, item)
#define VECTOR_INSERT(vec, idx, item) vector_insert(&vec, idx, item)
#define VECTOR_GET(vec, type, idx) (type) vector_get(&vec, idxx)
#define VECTOR_DELETE(vec, idx) vector_delete(&vec, idx)
#define VECTOR_TOTAL(vec) vector_total(&vec)
#define VECTOR_FREE(vec) vector_free(&vec)
typedef struct vector {
    point *items;
    int cap;
    int size;
} vector;

void vector_init(vector *);

int vector_total(vector *);

static void vector_resize(vector *, int);

void vector_add(vector *, point *);

void vector_set(vector *, int, point *);

void vector_insert(vector *, int, point *);

point *vector_get(vector *, int);

void vector_delete(vector *, int);

void vector_free(vector *);

#endif