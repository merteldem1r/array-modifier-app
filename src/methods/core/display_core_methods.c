#include <core_methods.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>
#include <utils.h>

void CoreMethodOperations(struct Array *arr, int operation) {
    switch (operation) {
        case DISPLAY: {
            printOperation("Display");
            displayCurrentTime();

            Display(arr);
            break;
        }
        case APPEND: {
            printOperation("Append");
            displayCurrentTime();

            printf("-> Enter number: ");
            const int num = getIntInput(INT_MIN, INT_MAX);
            PERFORMANCE_TEST(Append(arr, num), "Append");
            Display(arr);
            break;
        }
        case INSERT: {
            printOperation("Insert");
            displayCurrentTime();

            printf("-> Enter insert index: ");
            const int index = getIntInput(0, arr->length - 1);

            printf("-> Enter number to insert: ");
            const int num = getIntInput(INT_MIN, INT_MAX);

            PERFORMANCE_TEST(Insert(arr, index, num), "Insert");
            Display(arr);
            break;
        }
        case DELETE: {
            printOperation("Delete");
            displayCurrentTime();

            printf("-> Enter delete index: ");
            const int index = getIntInput(0, arr->length - 1);
            int res = -1;

            PERFORMANCE_TEST(Delete(arr, index, &res), "Delete");

            printConsoleMessage(1, "Deleted value: ");
            printf("%d\n", res);

            break;
        }
        case GET: {
            printOperation("Get");
            displayCurrentTime();

            printf("-> Enter index to get: ");
            const int index = getIntInput(0, arr->length);
            int res = -1;

            PERFORMANCE_TEST(Get(arr, index, &res), "Get");
            printConsoleMessage(1, "Found num: ");
            printf("%d\n", res);
            break;
        }
        case SET: {
            printOperation("Set");
            displayCurrentTime();

            printf("-> Enter index to set: ");
            const int index = getIntInput(0, arr->length - 1);

            printf("-> Enter number to set: ");
            const int num = getIntInput(INT_MIN, INT_MAX);

            int res = -1;

            PERFORMANCE_TEST(Set(arr, index, num, &res), "Set");

            printConsoleMessage(1, "Number set ");
            printf("Index: %d Number: %d\n", index, res);

            break;
        }
        default: break;
    }
}
