#include <search_methods.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils.h>

typedef struct {
    int value;
    int distance;
} ElementDistance;

int LinearSearch(const struct Array *arr, int key, int *resPtr) {
    /*
        Here is Suggestions for Improving Linear Search:
            1. Transposition (moving element i-1 index on each search)
            2. Move to Front (moving element to 0 index)
            3. Two Pointer Approach (in cases when chance of key on the end is same as on beginning)
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

int BinarySearch(const struct Array *arr, int key, int *resPtr) {
    int foundIdx = -1;
    int low = 0, high = arr->length - 1;

    while (low <= high) {
        const int mid = low + (high - low) / 2;

        if (arr->A[mid] == key) {
            foundIdx = mid;
            break;
        }

        if (arr->A[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (resPtr != NULL)
        *resPtr = foundIdx;

    return foundIdx;
}

int comp(const void *a, const void *b) {
    const ElementDistance *elemA = (ElementDistance *) a;
    const ElementDistance *elemB = (ElementDistance *) b;

    return elemA->distance - elemB->distance;
}

void FindKNearest(const struct Array *arr, int target, int k) {
    ElementDistance *distances = (ElementDistance *) malloc(arr->length * sizeof(ElementDistance));

    for (int i = 0; i < arr->length; ++i) {
        distances[i].value = arr->A[i];
        distances[i].distance = abs(target - arr->A[i]);
    }

    qsort(distances, arr->length, sizeof(distances[0]), comp);

    printConsoleMessage(1, "");
    printf(" The %d Nearest Elements to %d: { ", k, target);
    for (int i = 0; i < k  && i < 20 && i < arr->length; ++i) {
        printf("%d ", distances[i].value);
    }
    if (k > 15) {
        printf(" ... ");
    }
    printf("}\n");

    free(distances);
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
