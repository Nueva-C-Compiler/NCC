#include <stdio.h>
#include "vec.h"
#include "hashmap.c"

int main() {
    /* exit(1); */
    Vec test = vec_new();
    VEC_PUSH(int, &test, 32);
    printf("test[0] = %d\n", *VEC_AT(int, &test, 0));

    VEC_SHRINK(int, &test, 3);
    printf("Length: %zu\n", VEC_LEN(int, &test));

    VEC_PUSH(int, &test, 32);
    printf("test[0] = %d\n", *VEC_AT(int, &test, 0));

    VEC_PUSH(int, &test, 64);
    printf("test[1] = %d\n", *VEC_AT(int, &test, 1));

    printf("Length: %zu\n", VEC_LEN(int, &test));

    VEC_POP(int, &test);
    printf("Length: %zu\n", VEC_LEN(int, &test));

    VEC_POP(int, &test);
    printf("Length: %zu\n", VEC_LEN(int, &test));

    VEC_POP(int, &test);
    printf("Length: %zu\n", VEC_LEN(int, &test));

    VEC_POP(int, &test);
    printf("Length: %zu\n", VEC_LEN(int, &test));

    VEC_PUSH(int, &test, 128);
    printf("test[0] = %d\n", *VEC_AT(int, &test, 0));

    hashmap_t h;
    hashmap_init(&h, sizeof(int), sizeof(double));
    for (int i = 0; i < 128; i++) {
        int key = rand() % 128;
        double val = rand();        
        printf("Inserting pair %d %f\n", key, val);
        hashmap_set(&h, &key, &val);
    }
    for (int i = 0; i < 128; i++) {
        double val = *(double*)hashmap_get(&h, &i);
        printf("Read pair %d %f\n", i, val);
    }
}
