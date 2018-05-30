#include "utils/Utils.h"
#include "utils/Vector.h"


int main() {
    seed_rng();
    int size = 9;
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

    printf("\nTesting insert: inserting ");
    pt = generate_point();
    print_point(pt);
    printf(" at index %d \n", 5);
    VECTOR_INSERT(vec, 5, &pt);
    print_arr(vec.items, vec.size);

    printf("\nTesting delete: deleting at index %d\n", vec.size);
    VECTOR_DELETE(vec, vec.size);
    print_arr(vec.items, vec.size);


}
