#include <array.h>
#include <core_methods.h>
#include <limits.h>
#include <math.h>
#include <search_methods.h>
#include <sorting_methods.h>
#include <statistical_methods.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <transformation_methods.h>
#include <utils.h>

int main() {
    srand(clock());
    struct Array arr;

    // Initialize
    printf("\nEnter %ssize%s on HEAP for an array: ", T_UNDERLINE, P_RESET);
    arr.size = getIntInput(1, INT_MAX);

    printf("Enter %slength%s of an array: ", T_UNDERLINE, P_RESET);
    arr.length = getIntInput(1, arr.size);

    arr.A = (int32_t *) malloc(arr.size * sizeof(int32_t));

    printf("Do you want %sautomatically%s filled array? 1: YES 0: NO -> ", T_UNDERLINE, P_RESET);
    const int isFilled = getIntInput(0, 1);

    if (isFilled == 1) {
        printf("Do you want %srandom%s or %ssorted%s array? 1: Random 0: Sorted -> ", T_UNDERLINE, P_RESET, T_UNDERLINE,
               P_RESET);
        const int isRandom = getIntInput(0, 1);

        if (isRandom == 1) {
            printf("Enter %srange%s (min - max) of values in array: \n", T_UNDERLINE, P_RESET);

            printf("\tEnter min value -> ");
            const int32_t randomMin = getIntInput(-1000, 1000);

            printf("\tEnter max value -> ");
            const int32_t randomMax = getIntInput(randomMin + 1, 1000);

            printf("\n");
            PERFORMANCE_TEST(fillRandomNumbers(arr.A, arr.length, randomMin, randomMax), "fillRandomNumbers");
        } else {
            printf("\n");
            PERFORMANCE_TEST(fillSortedNumbers(arr.A, arr.length), "fillSortedNumbers");
        }
    } else if (isFilled == 0) {
        printf("Enter all elements: \n");
        for (int i = 0; i < arr.length; ++i) {
            printf("\tElement %d: ", i + 1);
            arr.A[i] = getIntInput(INT_MIN, INT_MAX);
        }
        printf("\n");
    } else {
        printConsoleMessage(0, "Invalid input passed");
        return -1;
    }

    const uint64_t memoryUsageBytes = arr.size * sizeof(int32_t);
    char *usedMemoryStr = memoryUsage(memoryUsageBytes);
    printf("Memory used on Heap: %s\n", usedMemoryStr);

    free(usedMemoryStr);
    Display(&arr);

    // Operations
    printf("\nChoose %sOperation%s on %sArray%s:\n\n", T_UNDERLINE, P_RESET, C_DATA, P_RESET);
    displayOperations();

    while (1) {
        printf("\n-> ");
        const int operation = getIntInput(0, 30);

        if (operation == 0) {
            free(arr.A);
            printConsoleMessage(1, "Array Deallocated");
            exit(1);
        }

        if (operation <= 6)
            CoreMethodOperations(&arr, operation);
        else if (operation <= 12)
            StatisticalMethodOperations(&arr, operation);
        else if (operation <= 18)
            TransformationMethodOperations(&arr, operation);
        else if (operation <= 24)
            SearchMethodOperations(&arr, operation);
        else if (operation <= 30)
            SortingMethodOperations(&arr, operation);
    }
}
