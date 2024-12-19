#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"

int Search(const struct Array *arr, int key, int *resPtr) {
    /*
        Here is Suggestions for Improving Linear Search:
            1. Transposition (moving element i-1 index on each search)
            2. Mo to Front (moving element to 0 index)
            3. Two Pointer Approach (in cases when chance of key on the end is same as on beginning)
            4. Binary Search (has O(logn) time complexity for sorted elements)
     */
    int foundIdx = -1;

    for (int i = 0; i < arr->length; ++i) {
        if (arr->A[i] == key) {
            foundIdx = i;
            break;
        }
    }

    if (resPtr != NULL)
        *resPtr = foundIdx;

    return foundIdx;
}

int Max(const struct Array *arr, int *resPtr) {
    if (arr->length == 0) {
        printf("Error: Max number not found\n");
        return -1;
    }

    int max = INT_MIN;

    for (int i = 0; i < arr->length; ++i) {
        if (arr->A[i] > max)
            max = arr->A[i];
    }

    if (resPtr != NULL)
        *resPtr = max;

    return max;
}

int Min(const struct Array *arr, int *resPtr) {
    if (arr->length == 0) {
        printf("Error: Min number not found\n");
        return -1;
    }

    int min = INT_MAX;

    for (int i = 0; i < arr->length; ++i) {
        if (arr->A[i] < min)
            min = arr->A[i];
    }

    if (resPtr != NULL)
        *resPtr = min;

    return min;
}

int IsSorted(const struct Array *arr, int *resPtr) {
    // non-descending order
    int isSorted = 1;

    for (int i = 0; i < arr->length - 1; ++i) {
        if (arr->A[i] > arr->A[i + 1]) {
            isSorted = 0;
            break;
        }
    }

    if (resPtr != NULL)
        *resPtr = isSorted;

    return isSorted;
}
