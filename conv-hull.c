#include "utils/Utils.h"
#include "utils/Vector.h"

vector *conv_hull(vector *arr);

int access_vector(void *foo, int idx, int offset) {
    vector *foo_vec = (vector *) foo;
    return *((int *) (&foo_vec->items[idx]) + offset);
}

int main(int argc, char *argv[]) {
    int num_points;
    if (argc == 2) {
        num_points = atoi(argv[1]);
    } else {
        printf("Usage: %s <number of points>\n", argv[0]);
        exit(0);
    }
    seed_rng();
    set_x_bound(50);
    set_y_bound(50);
    VECTOR_INIT(points);
    point tmp;
    for (int i = 0; i < num_points; i++) {
        tmp = generate_point();
        VECTOR_ADD(points, &tmp);
    }
    write_points("../../foo.pts", points.items, points.size);
    print_arr(points.items, points.size);
    printf("\n");
    printf("Testing access\nShould print 2nd y value: %d\n", access_vector((void *) &points, 1, 1));
    printf("\n\nITS THE MAIN EVENT\n");
    conv_hull(&points);


}

vector *conv_hull(vector *points) {
//    VECTOR_INIT(x_sorted);
//    free(x_sorted.items);
    vector x_sorted;
    vector_copy(points, &x_sorted);
    quicksort((void *) &x_sorted, 0, x_sorted.size, 0, access_vector, sizeof(point) * x_sorted.cap + sizeof(int) * 2);
//    quicksort((void *) y_sorted, 0, y_sorted->size, 0, access_vector, sizeof(point) * y_sorted->cap + sizeof(int) * 2);
    print_arr(x_sorted.items, x_sorted.size);


}
