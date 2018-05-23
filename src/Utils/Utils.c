#include "Utils.h"

// Quicksort, with extra bullshit to handle x and y
//void quicksort(void *arr, int low, int high, int offset, int (*access)(void *, int, int)) {
void quicksort(point *arr, int low, int high, int offset) {
    if (low < high) {
        int pi = partition(arr, low, high, offset);
        quicksort(arr, low, pi - 1, offset);
        quicksort(arr, pi + 1, high, offset);
    }
}

//int partition(void *arr, int low, int high, int offset, int (*access)(void *, int, int)) {
int partition(point *arr, int low, int high, int offset) {
    // Arr is an array of points (x and y) ints
    // Get arr[high] then use the offset to choose between x(0) and y(1)
    // Structs are contiguous in memory (the x and y values are right next to each other)
    // Add the size of one int to the pointer to x to get y
    int pivot = *((int *) (arr + high) + offset);
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        // Get the value of the either the X or the Y of arr[j]
        if (*((int *) (arr + j) + offset) <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void swap(point *a, point *b) {
    if (a->x == b->x && a->y == b->y)
        return;
    if (a->x != b->x) {
        a->x = a->x + b->x;
        b->x = a->x - b->x;
        a->x = a->x - b->x;
    }
    if (a->y != b->y) {
        a->y = a->y + b->y;
        b->y = a->y - b->y;
        a->y = a->y - b->y;
    }
}

void write_points(char *filename, point *points, int size) {
    FILE *fp = fopen(filename, "wb");
    char header[20];
    sprintf(header, "%d %d %d\n", size, x_bound, y_bound);
    fwrite(header, sizeof(char), strlen(header), fp);
    fwrite(points, sizeof(points), (size_t) size, fp);
}

bool in_triangle(point A, point B, point C, point P) {
    // Pretty jank way to check (make 3 triangles, and check if the areas add up to the original)
    float AO = (float) (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2;
    float A1 = (float) (A.x * (B.y - P.y) + B.x * (P.y - A.y) + P.x * (A.y - B.y)) / 2;
    float A2 = (float) (P.x * (B.y - C.y) + B.x * (C.y - P.y) + C.x * (P.y - B.y)) / 2;
    float A3 = (float) (A.x * (P.y - C.y) + P.x * (C.y - A.y) + C.x * (A.y - P.y)) / 2;
    return AO == A1 + A2 + A3;
}

void copy_arr(point *src, point *dst, int size) {
    for (int i = 0; i < size; i++) {
        dst[i] = *(src + i);
    }
}

void print_arr(point *arr, int len) {
    for (int i = 0; i < len; i++) {
        print_point(arr[i]);
    }
}


