#include "Utils/Utils.h"
#include "Utils/Vector.h"

int main() {
    seed_rng();
    int size = 5;
    VECTOR_INIT(vec);
    point pt;
    printf("Printing generated points\n");
    for (int i = 0; i < size; i++) {
        pt = generate_point();
        print_point(pt);
        VECTOR_ADD(vec, &pt);
    }
    printf("\nPrinting vector contents\n");
    print_arr(vec.items, vec.size);
    printf("\nInserting element\n");
    pt = generate_point();
    VECTOR_INSERT(vec, 0, &pt);
    print_arr(vec.items, vec.size);

}
