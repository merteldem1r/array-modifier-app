#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"

int Sum(const struct Array *arr) {
    int sum = 0;

    for (int i = 0; i < arr->length; ++i)
        sum += arr->A[i];

    return sum;
}

float Avg(const struct Array *arr) {
    return (float) Sum(arr) / (float) arr->length;
}
