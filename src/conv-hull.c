#include "Utils/Utils.h"
#include "Utils/LinkedList.h"

node *conv_hull(point *arr, int len);

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
    point points[num_points];
    for (int i = 0; i < num_points; i++) {
        points[i] = generate_point();
    }
    write_points("../../foo.pts", points, num_points);
    print_arr(points, num_points);
    printf("\n");


}

node *conv_hull(point *arr, int len){
    // Remember to free the point arrays before returning
    point *x_points = malloc(sizeof(point) * len);
    point *y_points = malloc(sizeof(point) * len);
    copy_arr(arr, x_points, len);
    copy_arr(arr, y_points, len);
    quicksort(x_points, 0, len, 0);
    quicksort(y_points, 0, len, 1);


}
