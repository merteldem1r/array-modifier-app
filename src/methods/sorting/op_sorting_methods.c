#include <core_methods.h>
#include <sorting_methods.h>
#include <stdio.h>
#include <time.h>
#include <utils.h>

void printSortedArray(const struct Array *arr) {
    printConsoleMessage(1, "Array is sorted\n");
    Display(arr);
}

void SortingMethodOperations(const struct Array *arr, int operation) {
    switch (operation) {
        case INSERTION_SORT:
            printOperation("Insertion Sort");
            displayCurrentTime();

            PERFORMANCE_TEST(InsertionSort(arr->A, arr->length), "InsertionSort");
            printSortedArray(arr);
            break;
        case SHELL_SORT:
            break;
        case MERGE_SORT:
            printOperation("Merge Sort");
            displayCurrentTime();

            PERFORMANCE_TEST(MergeSort(arr->A, 0, arr->length- 1), "MergeSort");
            printSortedArray(arr);
            break;
        case QUICK_SORT:
            break;
        case HEAP_SORT:
            break;
        default: break;
    }
}
