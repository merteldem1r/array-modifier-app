#include <limits.h>
#include <search_methods.h>
#include <stdio.h>
#include <time.h>
#include <utils.h>

void DisplaySearchMethods(const struct Array *arr, int operation) {
    switch (operation) {
        case LINEAR_SEARCH: {
            printOperation("Linear Search");
            displayCurrentTime();

            printf("-> Enter num to linear search: ");
            const int key = getIntInput(INT_MIN, INT_MAX);
            int res = -1;

            PERFORMANCE_TEST(LinearSearch(arr, key, &res), "LinearSearch");

            printConsoleMessage(1, "Found num at index: ");
            printf("%d\n", res);

            break;
        }
        case BINARY_SEARCH: {
            printOperation("Binary Search");
            displayCurrentTime();

            if (!IsSorted(arr, NULL)) {
                printConsoleMessage(0, "Array should be sorted for Binary Search method\n");
                break;
            }

            printf("-> Enter num to binary search: ");
            const int key = getIntInput(INT_MIN, INT_MAX);
            int res = -1;

            PERFORMANCE_TEST(BinarySearch(arr, key, &res), "BinarySearch");

            printConsoleMessage(1, "Found num at index: ");
            printf("%d\n", res);

            break;
        }
        case K_NEAREST: {
            printOperation("K-Nearest");
            displayCurrentTime();

            printf("-> Enter target number: ");
            const int target = getIntInput(INT_MIN, INT_MAX);

            printf("-> Enter how many nearest k: ");
            const int k = getIntInput(1, arr->length);

            PERFORMANCE_TEST(FindKNearest(arr, target, k), "FindKNearest");
            break;
        }
        case MAX: {
            printOperation("Max");
            displayCurrentTime();

            int res = 0;
            PERFORMANCE_TEST(Max(arr, &res), "Max");

            printConsoleMessage(1, "Max found number: ");
            printf("%d\n", res);
            break;
        }
        case MIN: {
            printOperation("Min");
            displayCurrentTime();

            int res = 0;
            PERFORMANCE_TEST(Max(arr, &res), "Min");

            printConsoleMessage(1, "Min found number: ");
            printf("%d\n", res);
            break;
        }
        case IS_SORTED: {
            printOperation("Is Sorted");
            displayCurrentTime();

            int res = 0;
            PERFORMANCE_TEST(IsSorted(arr, &res), "IsSorted");

            if (res)
                printConsoleMessage(1, "Array is Sorted in non-descending order");
            else
                printConsoleMessage(1, "Array is NOT Sorted in non-descending order");
            break;
        }
        default: break;
    }
}
