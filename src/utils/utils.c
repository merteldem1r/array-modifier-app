#include <math.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/utils.h"

void swap(int32_t *x, int32_t *y) {
    const int temp = *x;
    *x = *y;
    *y = temp;
}

// void PerformanceTest(void (*func)(), const char *funcName)
// {
//     clock_t startClock, endClock;
//     startClock = clock();

//     func();

//     endClock = clock();

//     double clockSeconds = (double)(endClock - startClock) / CLOCKS_PER_SEC;
//     printf("Function %s%c%s took: %s%f%s sec", C_OPTION, funcName, P_RESET, C_COMPLEXITY, clockSeconds, P_RESET);
// }

char *memoryUsage(uint64_t bytes) {
    const int bufferLen = 30;
    char *result = (char *) malloc(bufferLen * sizeof(char));
    double size = (double) bytes;
    char *sizeUnit;

    if (size < 1024) {
        sizeUnit = "B";
    } else if (size < pow(1024, 2)) {
        size /= 1024;
        sizeUnit = "KB";
    } else if (size < pow(1024, 3)) {
        size /= pow(1024, 2);
        sizeUnit = "MB";
    } else {
        size /= pow(1024, 3);
        sizeUnit = "GB";
    }


    sprintf(result, "%s%.3f%s %s", C_COMPLEXITY, size, P_RESET, sizeUnit);

    return result;
}

int32_t getIntInput(int32_t min, int32_t max) {
    char inputBuffer[100];
    const int32_t inputBase = 10;

    const char *inputPtr = fgets(inputBuffer, sizeof(inputBuffer), stdin);

    if (inputPtr == NULL) {
        printConsoleMessage(0, "Invalid input received");
        exit(1);
    }

    char *endPtr;
    const int64_t input = strtoll(inputBuffer, &endPtr, inputBase);

    if (*endPtr != '\n' && *endPtr != '\0') {
        printConsoleMessage(0, "Invalid input passed");
        exit(1);
    }

    if (input < min || input > max) {
        printConsoleMessage(0, "Input is out of the range");
        exit(1);
    }

    return (int32_t) input;
}

double getDoubleInput(double min, double max) {
    char inputBuffer[100];
    const char *inputPtr = fgets(inputBuffer, sizeof(inputBuffer), stdin);

    if (inputPtr == NULL) {
        printConsoleMessage(0, "Invalid input received");
        exit(1);
    }

    char *endPtr;
    const double input = strtod(inputBuffer, &endPtr);

    if (*endPtr != '\n' && *endPtr != '\0') {
        printConsoleMessage(0, "Invalid input passed");
        exit(1);
    }

    if (input < min || input > max) {
        printConsoleMessage(0, "Input is out of the range");
        exit(1);
    }

    return input;
}

void displayOperations() {
    // Core
    printf("\tCore Methods:\n");
    printf("    %s\t%-18s %-18s %-18s %-18s %-18s %-18s%s\n", C_OPTION,
           "1: Display", "2: Append", "3: Insert", "4: Delete", "5: Get", "6: Set", P_RESET);

    // Statistical
    printf("\tStatistical Methods:\n");
    printf("    %s\t%-18s %-18s %-18s %-18s %-18s %-18s%s\n", C_OPTION,
           "7: Sum", "8: Mean", "9: Median", "10: Mode", "11: Variance", "12: Standard Deviation", P_RESET);

    // Transformation
    printf("\tTransformation Methods:\n");
    printf("    %s\t%-18s %-18s %-18s %-18s %-18s %-18s%s\n", C_OPTION,
           "13: Reverse", "14: Left Shift", "15: Right Shift", "16: Rotate", "17: Scale", "18: Normalize", P_RESET);

    // Search
    printf("\tSearch Methods:\n");
    printf("    %s\t%-18s %-18s %-18s %-18s %-18s %-18s%s\n", C_OPTION,
           "19: Linear Search", "20: Binary Search", "21: K-Nearest", "22: Max", "23: Min", "24: Is Sorted", P_RESET);

    // Sorting
    printf("\tSorting Methods:\n");
    printf("    %s\t%-18s %-18s %-18s %-18s %-18s %-18s%s\n", C_OPTION,
           "25: Insertion Sort", "26: Shell Sort", "27: Merge Sort", "28: Quick Sort", "29: Count Sort",
           "30: Heap Sort",
           P_RESET);

    // Exit
    printf("\n\t%-18s%s", "0: Exit", P_RESET);
    printf("\n");
}

void printConsoleMessage(const int isSuccess, const char *message) {
    const char *WORD;
    const char *COLOR;

    if (isSuccess) {
        WORD = "SUCCESS ";
        COLOR = C_SUCCESS;
    } else {
        WORD = "ERROR ";
        COLOR = C_ERROR;
    }

    printf("%s%s%s%s", COLOR, WORD, P_RESET, message);
}

void printOperation(const char *operation) {
    printf("%sOperation%s: %s%s%s \n", T_UNDERLINE, P_RESET, C_OPTION, operation, P_RESET);
}

void displayCurrentTime() {
    time_t rawTime;
    time(&rawTime);
    const struct tm *timeInfo = localtime(&rawTime);

    char formatBuffer[12];
    strftime(formatBuffer, sizeof(formatBuffer), "%I:%M:%S %p", timeInfo);

    printf("%sOperation Time%s: %s\n", T_UNDERLINE, P_RESET, formatBuffer);
}

void fillRandomNumbers(int A[], size_t arrLen, int32_t min, int32_t max) {
    for (size_t i = 0; i < arrLen; ++i)
        A[i] = min + rand() % (max - min + 1);
}

void fillSortedNumbers(int A[], size_t arrLen) {
    for (int i = 0; i < arrLen; ++i)
        A[i] = i + 1;
}
