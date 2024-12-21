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

// Search Methods
int Max(const struct Array *arr, int *resPtr);
int Min(const struct Array *arr, int *resPtr);
int IsSorted(const struct Array *arr, int *resPtr);

#endif //SEARCH_METHODS_H
