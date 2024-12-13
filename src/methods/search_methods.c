#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"

int Search(struct Array *arr, int key)
{
    /*
        Suggestions for Improving Linear Search:
            1. Transposition (moving element i-1 index on each search)
            2. Mo to Front (moving element to 0 index)
            3. Two Pointer Approach (in cases when chance of key on the end is same as on beginning)
            4. Binary Search (has O(logn) time complexity for sorted elements)
     */

    for (int i = 0; i < arr->length; ++i)
    {
        if (arr->A[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int Max(struct Array *arr)
{
    if (arr->length == 0)
    {
        printf("Error: Max number not found\n");
        return -1;
    }

    int max = INT_MIN;

    for (int i = 0; i < arr->length; ++i)
    {
        if (arr->A[i] > max)
            max = arr->A[i];
    }

    return max;
}

int Min(struct Array *arr)
{
    if (arr->length == 0)
    {
        printf("Error: Min number not found\n");
        return -1;
    }

    int min = INT_MAX;

    for (int i = 0; i < arr->length; ++i)
    {
        if (arr->A[i] < min)
            min = arr->A[i];
    }

    return min;
}

int IsSorted(struct Array *arr)
{
    // non-descending order
    for (int i = 0; i < arr->length - 1; ++i)
    {
        if (arr->A[i] > arr->A[i + 1])
            return 0;
    }

    return 1;
}
