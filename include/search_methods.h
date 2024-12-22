//
// Created by Mert on 21.12.2024.
//

#ifndef SEARCH_METHODS_H
#define SEARCH_METHODS_H
#include "array.h"

#define LINEAR_SEARCH 19
#define BINARY_SEARCH 20
#define MAX 21
#define MIN 22
#define IS_SORTED 23

void DisplaySearchMethods(const struct Array *arr, int operation);

// Search Methods
int LinearSearch(const struct Array *arr, int key, int *resPtr);

int BinarySearch(const struct Array *arr, int key, int *resPtr);

int Max(const struct Array *arr, int *resPtr);

int Min(const struct Array *arr, int *resPtr);

int IsSorted(const struct Array *arr, int *resPtr);

#endif //SEARCH_METHODS_H
