#include <math.h>
#include <search_methods.h>
#include <statistical_methods.h>
#include <stdio.h>
#include <time.h>
#include <utils.h>

void DisplayStatisticalMethods(const struct Array *arr, int operation) {
    switch (operation) {
        case SUM: {
            printOperation("Sum");
            displayCurrentTime();

            int64_t res = 0;
            PERFORMANCE_TEST(Sum(arr->A, arr->length, &res), "Sum");

            printConsoleMessage(1, "Sum of all elements: ");
            printf("%lld\n", res);
            break;
        }
        case MEAN: {
            printOperation("Mean");
            displayCurrentTime();

            double res = 0;
            PERFORMANCE_TEST(Mean(arr, &res), "Mean");

            printConsoleMessage(1, "Average of all elements: ");
            printf("%.2f\n", res);
            break;
        }
        case MEDIAN: {
            printOperation("Median");
            displayCurrentTime();

            double resPtr = NAN;

            if (!IsSorted(arr, NULL)) {
                printConsoleMessage(0, "Array should be sorted for Median method\n");
                break;
            }

            PERFORMANCE_TEST(Median(arr, &resPtr), "Median");
            printConsoleMessage(1, "Median of the array: ");
            printf("%.1f\n", resPtr);

            break;
        }
        case MODE: {
            printOperation("Mode");
            displayCurrentTime();

            break;
        }
        case VARIANCE: {
            printOperation("Variance");
            displayCurrentTime();

            double resPtr = 0;
            PERFORMANCE_TEST(Variance(arr, &resPtr), "Variance");

            printConsoleMessage(1, "Variance of the array: ");
            printf("%.5f\n", resPtr);

            break;
        }
        case STANDARD_DEVIATION: {
            printOperation("Standard Deviation");
            displayCurrentTime();

            double resPtr = 0;
            PERFORMANCE_TEST(StandardDeviation(arr, &resPtr), "StandardDeviation");

            printConsoleMessage(1, "Standard Deviation of the array: ");
            printf("%.5f\n", resPtr);

            break;
        }
        default: break;
    }
}
