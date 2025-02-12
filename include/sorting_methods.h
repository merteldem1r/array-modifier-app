//
// Created by Mert on 21.12.2024.
//

#ifndef SORTING_METHODS_H
#define SORTING_METHODS_H
#include <array.h>
#include <stddef.h>

#define INSERTION_SORT 25
#define SHELL_SORT 26
#define MERGE_SORT 27
#define QUICK_SORT 28
#define COUNT_SORT 29
#define HEAP_SORT 30

void SortingMethodOperations(const struct Array *arr, int operation);

// Sorting Methods
void InsertionSort(int A[], size_t arrLen);

void ShellSort(int A[], int32_t arrLen);

void MergeSort(int A[], int32_t low, int32_t high);

void QuickSort(int A[], int32_t low, int32_t high);

void HeapSort(int A[], int32_t arrLen);


#endif //SORTING_METHODS_H
