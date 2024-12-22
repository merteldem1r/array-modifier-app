#include <core_methods.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>
#include <transformation_methods.h>
#include <utils.h>

void DisplayTransformationMethods(const struct Array *arr, int operation) {
    switch (operation) {
        case REVERSE: {
            printOperation("Reverse");
            displayCurrentTime();

            PERFORMANCE_TEST(Reverse(arr), "Reverse");
            printConsoleMessage(1, "Elements reversed\n");
            Display(arr);
            break;
        }
        case LEFT_SHIFT: {
            printOperation("Lest Shift");
            displayCurrentTime();

            PERFORMANCE_TEST(LeftShift(arr), "LeftShift");
            printConsoleMessage(1, "Elements left shifted\n");
            Display(arr);
            break;
        }
        case RIGHT_SHIFT: {
            printOperation("Right Shift");
            displayCurrentTime();

            PERFORMANCE_TEST(RightShift(arr), "RightShift");
            printConsoleMessage(1, "Elements right shifted\n");
            Display(arr);
            break;
        }
        case ROTATE: {
            printOperation("Rotate");
            displayCurrentTime();

            printf("-> Enter non-negative Rotate step: ");
            const int k = getIntInput(0, INT_MAX);

            PERFORMANCE_TEST(Rotate(arr, k), "Rotate");
            printConsoleMessage(1, "Elements right rotated\n");
            Display(arr);
            break;
        }
        default: break;
    }
}
