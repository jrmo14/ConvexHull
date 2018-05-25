#include "utils/Utils.h"
#include "utils/Vector.h"

int access_vector(vector *vec, int idx, int offset) {

    if (idx < 0 || idx > vec->size)
        return -1000;
    point *point_val = &vec->items[idx];
    int int_val = *((int *) (point_val) + offset);
    return int_val;
}

vector *conv_hull(vector *points) {
    vector x_sorted;
    vector_copy(points, &x_sorted);
    int (*access_ptr)(vector *, int, int) = &access_vector;
    quicksort(&x_sorted, 0, x_sorted.size, 1, access_ptr);
    print_arr(x_sorted.items, x_sorted.size);

}

int main(int argc, char *argv[]) {
    int num_points;
    if (argc == 2) {
        num_points = atoi(argv[1]);
    } else {
        printf("Usage: %s <number of points>\n", argv[0]);
        exit(0);
    }
    //seed_rng();
    set_x_bound(50);
    set_y_bound(50);
    VECTOR_INIT(points);
    point tmp;
    for (int i = 0; i < num_points; i++) {
        tmp = generate_point();
        VECTOR_ADD(points, &tmp);
    }
    write_points("../../foo.pts", points.items, points.size);
    printf("\n");
    printf("Testing access\nShould print 4th y value: %d\n", access_vector((void *) &points, 3, 1));
    print_arr(points.items, points.size);
    printf("\n\n");

    conv_hull(&points);
}
