#include "Point.h"

int y_bound = 20;
int x_bound = 20;
bool seeded = false;

void seed_rng() {
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }
}

void set_x_bound(int x) {
    x_bound = x;
}

void set_y_bound(int y) {
    y_bound = y;
}

point generate_point() {
    point ret;
    ret.x = rand() % x_bound;
    ret.y = rand() % y_bound;
    return ret;
}

int get_x_bound() {
    return x_bound;
}

int get_y_bound() {
    return y_bound;
}

void print_point(point foo) {
    printf("{%d, %d}", foo.x, foo.y);
}

point point_factory(int x, int y) {
    point foo;
    foo.x = x;
    foo.y = y;
    return foo;
}