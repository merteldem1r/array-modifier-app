#include <stddef.h>

#include "../include/array.h"
#include "../include/sorting_methods.h"

void InsertionSort(int A[], size_t arrLen) {
    for (int i = 1; i < arrLen; i++) {
        const int key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            --j;
        }

        A[j + 1] = A[j];
    }
}
