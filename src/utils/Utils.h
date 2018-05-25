#ifndef UTILS_H
#define UTILS_H
// This is a header file, it describes the functions available
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Point.h"
#include "Vector.h"


// TODO use a function pointer to access the data
// TODO pass a void * instead a of point *
// TODO access function must take a void *, an index, and an offset
// Stuff for quicksort
void quicksort(vector *arr, int low, int high, int offset, int (*num_access)(vector *, int, int));

int partition(vector *arr, int low, int high, int offset, int (*num_access)(vector *, int, int));

void swap(point *a, point *b);

// Random stuff
void print_arr(point *arr, int len);

bool in_triangle(point A, point B, point C, point test);

void copy_arr(point *src, point *dst, int size);

void write_points(char *filename, point *points, int size);

#endif