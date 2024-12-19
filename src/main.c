#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/array.h"

int main() {
    struct Array arr;

    // Initialize Array on HEAP
    printf("Enter %ssize%s on HEAP for an array: ", T_UNDERLINE, P_RESET);
    arr.size = getIntInput(INT_MIN, INT_MAX);

    if (arr.size <= 0) {
        printConsoleMessage(0, "Array size must be positive");
        return 1;
    }

    printf("Enter %slength%s of an array: ", T_UNDERLINE, P_RESET);
    arr.length = getIntInput(INT_MIN, INT_MAX);

    if (arr.length > arr.size) {
        printConsoleMessage(0, "Number of elements can not be greater than allocated size");
        return 1;
    }

    arr.A = (int *) malloc(arr.size * sizeof(int));

    printf("Do you want %sautomatic%s filled array? 1: YES 0: NO -> ", T_UNDERLINE, P_RESET);
    const int isFilled = getIntInput(0, 1);

    if (isFilled == 1) {
        printf("Do you want %srandom%s or %ssorted%s array? 1: Random 0: Sorted -> ", T_UNDERLINE, P_RESET, T_UNDERLINE,
               P_RESET);
        const int isRandom = getIntInput(0, 1);

        if (isRandom == 1) {
            PERFORMANCE_TEST(fillRandomNumbers(arr.A, arr.length), "fillRandomNumbers");
        } else {
            PERFORMANCE_TEST(fillSortedNumbers(arr.A, arr.length), "fillSortedNumbers");
        }
    } else if (isFilled == 0) {
        printf("Enter all elements: \n");
        for (int i = 0; i < arr.length; ++i) {
            printf("\tElement %d: ", i + 1);
            arr.A[i] = getIntInput(INT_MIN, INT_MAX);
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
        const int option = getIntInput(0, 30);

        switch (option) {
            case DISPLAY:
                Display(&arr);
                break;

            case APPEND: {
                printf("Enter number: ");
                const int num = getIntInput(INT_MIN, INT_MAX);

                PERFORMANCE_TEST(Append(&arr, num), "Appends");
                break;
            }
            case INSERT: {
                printf("Enter insert index: ");
                const int index = getIntInput(0, arr.length - 1);

                printf("Enter number to insert: ");
                const int num = getIntInput(INT_MIN, INT_MAX);

                PERFORMANCE_TEST(Insert(&arr, index, num), "Insert");
                break;
            }
            case DELETE: {
                printf("Enter delete index: ");
                const int index = getIntInput(0, arr.length - 1);
                int res = -1;

                PERFORMANCE_TEST(Delete(&arr, index, &res), "Delete");

                printConsoleMessage(1, "Deleted value: ");
                printf("%d", res);

                break;
            }
            case SEARCH: {
                printf("Enter num to search: ");
                const int key = getIntInput(INT_MIN, INT_MAX);
                int res = -1;

                PERFORMANCE_TEST(Search(&arr, key, &res), "Search");

                printConsoleMessage(1, "Found num at index: ");
                printf("%d", res);

                break;
            }
            case GET: {
                printf("Enter index to get: ");
                const int index = getIntInput(0, arr.length);
                int res = -1;

                PERFORMANCE_TEST(Get(&arr, index, &res), "Get");
                printConsoleMessage(1, "Found num: ");
                printf("%d", res);
                break;
            }
            case SET: {
                printf("Enter index to set: ");
                const int index = getIntInput(0, arr.length - 1);

                printf("Enter number to set: ");
                const int num = getIntInput(INT_MIN, INT_MAX);

                int res = -1;

                PERFORMANCE_TEST(Set(&arr, index, num, &res), "Set");

                printConsoleMessage(1, "Number set ");
                printf("At index: %d Number: %d", index, res);

                break;
            }
            case MAX: {
                int res = 0;
                PERFORMANCE_TEST(Max(&arr, &res), "Max");

                printConsoleMessage(1, "Max found number: ");
                printf("%d", res);
                break;
            }
            case MIN: {
                int res = 0;
                PERFORMANCE_TEST(Max(&arr, &res), "Min");

                printConsoleMessage(1, "Min found number: ");
                printf("%d", res);
                break;
            }
            case SUM: {
                int res = 0;
                PERFORMANCE_TEST(Sum(&arr, &res), "Sum");

                printConsoleMessage(1, "Sum of all elements:");
                printf("%d", res);
                break;
            }
            case AVG: {
                float res = 0;
                PERFORMANCE_TEST(Avg(&arr, &res), "Avg");

                printConsoleMessage(1, "Average of all elements:");
                printf("%.3f", res);
                break;
            }
            case REVERSE: {
                PERFORMANCE_TEST(Reverse(&arr), "Reverse");
                printConsoleMessage(1, "Elements reversed\n");
                Display(&arr);
                break;
            }
            case LEFT_SHIFT: {
                PERFORMANCE_TEST(LeftShift(&arr), "LeftShift");
                printConsoleMessage(1, "Elements left shifted\n");
                Display(&arr);
                break;
            }
            case RIGHT_SHIFT: {
                PERFORMANCE_TEST(RightShift(&arr), "RightShift");
                printConsoleMessage(1, "Elements right shifted\n");
                Display(&arr);
                break;
            }
            case ROTATE: {
                printf("Enter non-negative Rotate step: ");
                const int k = getIntInput(0, INT_MAX);

                PERFORMANCE_TEST(Rotate(&arr, k), "Rotate");
                printConsoleMessage(1, "Elements right rotated\n");
                Display(&arr);
                break;
            }
            case IS_SORTED: {
                int res = 0;
                PERFORMANCE_TEST(IsSorted(&arr, &res), "IsSorted");

                if (res)
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
