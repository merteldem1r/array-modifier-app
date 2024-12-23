//
// Created by Mert on 21.12.2024.
//

#ifndef CORE_METHODS_H
#define CORE_METHODS_H
#include "array.h"

#define DISPLAY 1
#define APPEND 2
#define INSERT 3
#define DELETE 4
#define GET 5
#define SET 6

void CoreMethodOperations(struct Array *arr, int operation);

// Core Methods
void Resize(struct Array *arr);

void Display(const struct Array *arr);

void Append(struct Array *arr, const int num);

void Insert(struct Array *arr, int index, int num);

int Delete(struct Array *arr, int index, int *resPtr);

int Get(const struct Array *arr, int index, int *resPtr);

int Set(const struct Array *arr, int index, int num, int *resPtr);

#endif //CORE_METHODS_H
