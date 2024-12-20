#ifndef ARRAY_H
#define ARRAY_H
#include <stdint.h>

struct Array {
    int *A;
    int32_t size;
    int32_t length;
};

// METHODS

// Core
#define DISPLAY 1
#define APPEND 2
#define INSERT 3
#define DELETE 4
#define GET 5
#define SET 6

// Statistical
#define SUM 7
#define MEAN 8
#define MEDIAN 9
#define MODE 10
#define VARIANCE 11
#define STANDARD_DEVIATION 12

// Transformation
#define REVERSE 13
#define LEFT_SHIFT 14
#define RIGHT_SHIFT 15
#define ROTATE 16

// Search
#define LINEAR_SEARCH 19
#define BINARY_SEARCH 20
#define MAX 21
#define MIN 22
#define IS_SORTED 23

// Sorting
#define INSERTION_SORT 25
#define MERGE_SORT 26
#define QUICK_SORT 27
#define COUNT_SORT 28

#define EXIT 0

// Text
#define P_RESET "\033[0m"
#define C_SUCCESS "\033[32m"
#define C_ERROR "\033[31m"
#define C_DATA "\033[96m"
#define C_OPTION "\033[95m"
#define C_COMPLEXITY "\033[93m"
#define T_UNDERLINE "\033[4m"

#define PERFORMANCE_TEST(func, funcName)                      \
    do                                                        \
    {                                                         \
        clock_t startClock = clock();                         \
        func;                                                 \
        clock_t endClock = clock();                           \
        double clockSeconds =                                 \
            (double)(endClock - startClock) / CLOCKS_PER_SEC; \
        printf(                                               \
            "CPU Time for %s%s()%s: %s%f%s seconds\n",        \
            C_OPTION, funcName, P_RESET,                      \
            C_COMPLEXITY, clockSeconds, P_RESET);             \
    } while (0)

// METHODS

// Core Methods
void Resize(struct Array *arr);

void Display(const struct Array *arr);

void Append(struct Array *arr, const int num);

void Insert(struct Array *arr, int index, int num);

int Delete(struct Array *arr, int index, int *resPtr);

int LinearSearch(const struct Array *arr, int key, int *resPtr);

int BinarySearch(const struct Array *arr, int key, int *resPtr);

int Get(const struct Array *arr, int index, int *resPtr);

int Set(const struct Array *arr, int index, int num, int *resPtr);

// Search Methods
int Max(const struct Array *arr, int *resPtr);

int Min(const struct Array *arr, int *resPtr);

int IsSorted(const struct Array *arr, int *resPtr);

// Statistics Methods
float Mean(const struct Array *arr, float *resPtr);

int Sum(const int A[], size_t arrLen, int *resPtr);

float Median(const struct Array *arr, float *resPtr);

int Mode(const struct Array *arr, int *resPtr);

double Variance(const struct Array *arr, double *resPtr);

double StandardDeviation(const struct Array *arr, double *resPtr);

// Transformations Methods
void Reverse(const struct Array *arr);

void LeftShift(const struct Array *arr);

void RightShift(const struct Array *arr);

void Rotate(const struct Array *arr, int k);

// Sorting Methods
void InsertionSort(int A[], size_t arrLen);

// UTILS

// void PerformanceTest(void (*func)(), const char *funcName);

int32_t getIntInput(int min, int max);

char *memoryUsage(uint64_t bytes);

void displayOptions();

void printConsoleMessage(int isSuccess, const char *message);

void swap(int *x, int *y);

void fillRandomNumbers(int A[], size_t arrLen);

void fillSortedNumbers(int A[], size_t arrLen);

#endif
