#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "../include/array.h"

int Sum(const int A[], size_t arrLen, int *resPtr) {
    int sum = 0;

    for (int i = 0; i < arrLen; ++i)
        sum += A[i];

    if (resPtr != NULL)
        *resPtr = sum;

    return sum;
}

float Mean(const struct Array *arr, float *resPtr) {
    const float mean = (float) Sum(arr->A, arr->length, NULL) / (float) arr->length;

    if (resPtr != NULL)
        *resPtr = mean;

    return mean;
}

float Median(const struct Array *arr, float *resPtr) {
    float median = 0;
    const int mid = arr->length / 2;

    if (!IsSorted(arr, NULL)) {
        printConsoleMessage(0, "Array should be sorted for Median method\n");
        median = NAN;
    } else {
        if (arr->length % 2 == 0) {
            median = (float) (arr->A[mid - 1] + arr->A[mid]) / 2;
        } else {
            median = (float) arr->A[mid];
        }
    }

    if (resPtr != NULL)
        *resPtr = median;

    return median;
}

// int Mode(const struct Array *arr, int *resPtr) {
//     int mode = NAN;
//     int freqArr[arr->length];
//
//     for (int i = 0; i < arr->length; ++i) {
//         if ()
//     }
//
//     if (resPtr != NULL)
//         *resPtr = mode;
//
//     return mode;
// }

double Variance(const struct Array *arr, double *resPtr) {
    double variance = 0;
    const float mean = Mean(arr, NULL);

    double squaredDiffSum = 0;

    for (int i = 0; i < arr->length; ++i)
        squaredDiffSum += pow(mean - (float) arr->A[i], 2);

    variance = squaredDiffSum / arr->length;

    if (resPtr != NULL)
        *resPtr = variance;

    return variance;
}

double StandardDeviation(const struct Array *arr, double *resPtr) {
    const double standDev = sqrt(Variance(arr, NULL));

    if (resPtr != NULL)
        *resPtr = standDev;

    return standDev;
}
