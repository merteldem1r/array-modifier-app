#include <stdio.h>
#include "../include/array.h"

int Sum(const struct Array *arr, int *resPtr) {
    int sum = 0;

    for (int i = 0; i < arr->length; ++i)
        sum += arr->A[i];

    if (resPtr != NULL)
        *resPtr = sum;

    return sum;
}

float Avg(const struct Array *arr, float *resPtr) {
    const float avg = (float) Sum(arr, NULL) / (float) arr->length;

    if (resPtr != NULL)
        *resPtr = avg;

    return avg;
}
