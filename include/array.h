#ifndef ARRAY_H
#define ARRAY_H

struct Array {
    int *A;
    int size;
    int length;
};

#define DISPLAY 1
#define APPEND 2
#define INSERT 3
#define DELETE 4
#define SEARCH 5
#define GET 6
#define SET 7
#define MAX 8
#define MIN 9
#define SUM 10
#define AVG 11
#define REVERSE 12
#define LEFT_SHIFT 13
#define RIGHT_SHIFT 14
#define ROTATE 16
#define IS_SORTED 17
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
            "CPU Time for %s%s()%s: %s%f%s seconds\n",         \
            C_OPTION, funcName, P_RESET,                      \
            C_COMPLEXITY, clockSeconds, P_RESET);                \
    } while (0)

// METHODS

// Core Methods
void Resize(struct Array *arr);

void Display(const struct Array *arr);

void Append(struct Array *arr, const int num);

void Insert(struct Array *arr, int index, int num);

int Delete(struct Array *arr, int index);

int Search(const struct Array *arr, int key);

int Get(const struct Array *arr, int index);

int Set(const struct Array *arr, int index, int num);

// Search Methods
int Max(const struct Array *arr);

int Min(const struct Array *arr);

int IsSorted(const struct Array *arr);

// Statistics Methods
float Avg(const struct Array *arr);

int Sum(const struct Array *arr);

// Transformations Methods
void Reverse(const struct Array *arr);

void LeftShift(const struct Array *arr);

void RightShift(const struct Array *arr);

void Rotate(const struct Array *arr, int k);

// Sorting Methods
void InsertionSort(int A[], int arrLen);

// UTILS

// void PerformanceTest(void (*func)(), const char *funcName);

int getIntInput(int min, int max);

char *memoryUsage(int bytes);

void displayOptions();

void printConsoleMessage(int isSuccess, const char *message);

void swap(int *x, int *y);

void fillRandomNumbers(int A[], int arrLen);

void fillSortedNumbers(int A[], int arrLen);

#endif
