#include "Utils/Utils.h"

int main() {
    seed_rng();
    int size = 5;
    point points[size];
    point *points_copy = malloc(sizeof(point));
    for (int i = 0; i < size; i++) {
        points[i] = generate_point();
    }
    printf("Original: ");
    print_arr(points, size);

    copy_arr(points, points_copy, size);
    printf("\nCopied: ");
    print_arr(points_copy, size);

    quicksort(points, 0, size, 0);
    printf("\nX sorted: ");
    print_arr(points, size);

    // IDFK but doesn't work with the same numbers
    quicksort(points_copy, 0, size, 1);
    printf("\nY sorted: ");
    print_arr(points_copy, size);
}
