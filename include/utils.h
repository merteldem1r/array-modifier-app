//
// Created by Mert on 21.12.2024.
//

#ifndef UTILS_H
#define UTILS_H
#include "array.h"

#define P_RESET "\033[0m"
#define C_SUCCESS "\033[32m"
#define C_ERROR "\033[31m"
#define C_DATA "\033[96m"
#define C_OPTION "\033[95m"
#define C_COMPLEXITY "\033[93m"
#define T_UNDERLINE "\033[4m"

#define PERFORMANCE_TEST(func, funcName)                              \
    do {                                                              \
        clock_t startClock = clock();                                 \
        func;                                                         \
        clock_t endClock = clock();                                   \
        double clockSeconds =                                         \
            (double)(endClock - startClock) / CLOCKS_PER_SEC;         \
        printf(                                                       \
            "CPU Time for %s%s()%s: %s%f%s seconds\n",                \
            C_OPTION, funcName, P_RESET,                              \
            C_COMPLEXITY, clockSeconds, P_RESET);                     \
    } while (0)


// Utils
int32_t getIntInput(int min, int max);

char *memoryUsage(uint64_t bytes);

void displayOperations();

void printConsoleMessage(int isSuccess, const char *message);

void printOperation(const char* operation);

void displayCurrentTime();

void swap(int *x, int *y);

void fillRandomNumbers(int A[], size_t arrLen);

void fillSortedNumbers(int A[], size_t arrLen);


#endif //UTILS_H
