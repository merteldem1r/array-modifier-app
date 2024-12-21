//
// Created by Mert on 21.12.2024.
//

#ifndef STATISTICAL_METHODS_H
#define STATISTICAL_METHODS_H
#include "array.h"

#define SUM 7
#define MEAN 8
#define MEDIAN 9
#define MODE 10
#define VARIANCE 11
#define STANDARD_DEVIATION 12

// Statistical Methods
double Mean(const struct Array *arr, double *resPtr);
int64_t Sum(const int A[], size_t arrLen, int64_t *resPtr);
double Median(const struct Array *arr, double *resPtr);
int Mode(const struct Array *arr, int *resPtr);
double Variance(const struct Array *arr, double *resPtr);
double StandardDeviation(const struct Array *arr, double *resPtr);

#endif //STATISTICAL_METHODS_H
