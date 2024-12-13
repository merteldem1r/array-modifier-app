#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"

void Reverse(struct Array *arr)
{
    int l = 0, r = arr->length - 1;

    while (l < r)
    {
        swap(&arr->A[l], &arr->A[r]);
        ++l, --r;
    }
}

void LeftShift(struct Array *arr)
{
    int prev = arr->A[arr->length - 1];
    arr->A[arr->length - 1] = 0;

    for (int i = arr->length - 2; i >= 0; --i)
    {
        int temp = arr->A[i];
        arr->A[i] = prev;
        prev = temp;
    }
}

void RightShift(struct Array *arr)
{
    int prev = arr->A[0];
    arr->A[0] = 0;

    for (int i = 1; i < arr->length; ++i)
    {
        int temp = arr->A[i];
        arr->A[i] = prev;
        prev = temp;
    }
}

void Rotate(struct Array *arr, int k)
{
    // rotate the array to the right by k steps.

    if (k < 0)
    {
        printf("\t\t** Error: Invalid negative step for Rotate\n");
        return;
    }

    if (arr->length == 1 || k == 0 || k % arr->length == 0)
        return;

    if (arr->length == 2)
    {
        if (k % 2 != 0)
            swap(&arr->A[0], &arr->A[1]);
        return;
    }

    const int arrLen = arr->length;
    int *temp = (int *)malloc(arrLen * sizeof(int));

    for (int i = 0; i < arrLen; ++i)
        temp[(i + k) % arrLen] = arr->A[i];

    for (int i = 0; i < arrLen; ++i)
        arr->A[i] = temp[i];

    free(temp);
}
