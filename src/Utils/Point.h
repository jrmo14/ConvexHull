// Prevent point from being re-declared
#ifndef POINT_H
#define POINT_H
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
extern bool seeded;
extern int x_bound;
extern int y_bound;


typedef struct point {
    int x, y;
} point;

// Stuff for generating points
point generate_point();

void seed_rng();

void set_x_bound(int x);

void set_y_bound(int y);

point point_factory(int x, int y);

void print_point(point foo);

#endif