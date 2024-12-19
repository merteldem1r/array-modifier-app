#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/array.h"

int main() {
    struct Array arr;

    // Initialize Array on HEAP
    printf("Enter %ssize%s on HEAP for an array: ", T_UNDERLINE, P_RESET);
    arr.size = getIntegerInput(INT_MIN, INT_MAX);

    if (arr.size <= 0) {
        printConsoleMessage(0, "Array size must be positive");
        return 1;
    }

    printf("Enter %slength%s of an array: ", T_UNDERLINE, P_RESET);
    arr.length = getIntegerInput(INT_MIN, INT_MAX);

    if (arr.length > arr.size) {
        printConsoleMessage(0, "Number of elements can not be greater than allocated size");
        return 1;
    }

    arr.A = (int *) malloc(arr.size * sizeof(int));

    printf("Do you want %sautomatic%s filled array? 1: YES 0: NO -> ", T_UNDERLINE, P_RESET);
    const int isFilled = getIntegerInput(0, 1);

    if (isFilled == 1) {
        printf("Do you want %srandom%s or %ssorted%s array? 1: Random 0: Sorted -> ", T_UNDERLINE, P_RESET, T_UNDERLINE,
               P_RESET);
        const int isRandom = getIntegerInput(0, 1);

        if (isRandom == 1) {
            PERFORMANCE_TEST(fillRandomNumbers(arr.A, arr.length), "fillRandomNumbers");
        } else {
            PERFORMANCE_TEST(fillSortedNumbers(arr.A, arr.length), "fillSortedNumbers");
        }
    } else if (isFilled == 0) {
        printf("Enter all elements: \n");
        for (int i = 0; i < arr.length; ++i) {
            printf("\tElement %d: ", i + 1);
            arr.A[i] = getIntegerInput(INT_MIN, INT_MAX);
        }
    } else {
        printConsoleMessage(0, "Invalid input passed");
        return -1;
    }

    char *usedMemory = memoryUsage(arr.size * (int) sizeof(int));
    printf("Memory used on Heap: %s\n", usedMemory);
    free(usedMemory);
    Display(&arr);

    // Array Manipulations
    printf("\n");
    printf("\nChoose Option on %sArray%s:  \n", C_DATA, P_RESET);
    displayOptions();

    while (1) {
        printf("\n-> ");
        const int option = getIntegerInput(0, 30);

        switch (option) {
            case DISPLAY:
                Display(&arr);
                break;

            case APPEND: {
                printf("\tEnter number: ");
                const int num = getIntegerInput(INT_MIN, INT_MAX);
                PERFORMANCE_TEST(Append(&arr, num), "APPEND");
                break;
            }
            case INSERT: {
                printf("\tEnter insert index: ");
                const int index = getIntegerInput(0, arr.length - 1);

                printf("\tEnter number to insert: ");
                const int num = getIntegerInput(INT_MIN, INT_MAX);

                PERFORMANCE_TEST(Insert(&arr, index, num), "INSERT");
                break;
            }
            case DELETE: {
                printf("\tEnter delete index: ");
                const int index = getIntegerInput(0, arr.length - 1);

                printConsoleMessage(1, "Deleted value: ");
                printf("%d\n", Delete(&arr, index));
                break;
            }
            case SEARCH: {
                printf("\tEnter num to search: ");
                const int key = getIntegerInput(INT_MIN, INT_MAX);
                printConsoleMessage(1, "Found num at index: ");
                printf("%d\n", Search(&arr, key));
                break;
            }
            case GET: {
                printf("\tEnter index to get: ");
                const int index = getIntegerInput(0, arr.length);
                printConsoleMessage(1, "Found num: ");
                printf("%d\n", Get(&arr, index));
                break;
            }
            case SET: {
                printf("\tEnter index to set: ");
                const int index = getIntegerInput(0, arr.length - 1);

                printf("\tEnter number to set: ");
                const int num = getIntegerInput(INT_MIN, INT_MAX);
                printConsoleMessage(1, "Number setted at index:");
                printf("Num: %d\n Index: %d\n", Set(&arr, index, num), index);
                break;
            }
            case MAX: {
                printConsoleMessage(1, "Max found number:");
                printf("%d\n", Max(&arr));
                break;
            }
            case MIN: {
                printConsoleMessage(1, "Min found number:");
                printf("%d\n", Min(&arr));
                break;
            }
            case SUM: {
                printConsoleMessage(1, "Sum of all elements:");
                printf("%d\n", Sum(&arr));
                break;
            }
            case AVG: {
                printConsoleMessage(1, "Average of all elements:");
                printf("%.2f\n", Avg(&arr));
                break;
            }
            case REVERSE: {
                Reverse(&arr);
                printConsoleMessage(1, "Elements reversed");
                Display(&arr);
                break;
            }
            case LEFT_SHIFT: {
                LeftShift(&arr);
                printConsoleMessage(1, "Elements left shifted");
                Display(&arr);
                break;
            }
            case RIGHT_SHIFT: {
                RightShift(&arr);
                printConsoleMessage(1, "Elements right shifted");
                Display(&arr);
                break;
            }
            case ROTATE: {
                printf("\tEnter non-negative Rotate step: ");
                const int k = getIntegerInput(0, INT_MAX);

                PERFORMANCE_TEST(Rotate(&arr, k), "ROTATE");
                printConsoleMessage(1, "Elements right rotated");
                Display(&arr);
                break;
            }
            case IS_SORTED: {
                if (IsSorted(&arr))
                    printConsoleMessage(1, "Array is Sorted in non-descending order");
                else
                    printConsoleMessage(1, "Array is NOT Sorted in non-descending order");
                break;
            }

            case EXIT:
                free(arr.A);
                arr.A = NULL;
                exit(1);

            default:
                free(arr.A);
                arr.A = NULL;
                return 0;
        }
    }
}
