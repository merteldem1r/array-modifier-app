#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/array.h"

// void PerformanceTest(void (*func)(), const char *funcName)
// {
//     clock_t startClock, endClock;
//     startClock = clock();

//     func();

//     endClock = clock();

//     double clockSeconds = (double)(endClock - startClock) / CLOCKS_PER_SEC;
//     printf("Function %s%c%s took: %s%f%s sec", C_OPTION, funcName, C_RESET, C_SECONDS, clockSeconds, C_RESET);
// }

void displayOptions()
{
    printf("%s", C_OPTION);
    printf("\t1: Display\t6: Get\t\t11: Avg\t\t17: Is Sorted\n");
    printf("\t2: Append\t7: Set\t\t12: Reverse\n");
    printf("\t3: Insert\t8: Max\t\t13: Left Shift\n");
    printf("\t4: Delete\t9: Min\t\t14: Right Shift\n");
    printf("\t5: Search\t10: Sum\t\t16: Rotate\n");

    printf("\n\t0: Exit%s", C_RESET);
    printf("\n");
}

void printConsoleMessage(int isSuccess, const char *message)
{
    const char *WORD = "";
    const char *COLOR = "";

    if (isSuccess)
    {
        WORD = "SUCCESS -> ";
        COLOR = C_SUCCESS;
    }
    else
    {
        WORD = "ERROR -> ";
        COLOR = C_ERROR;
    }

    printf("%s%s%s%s\n", COLOR, WORD, C_RESET, message);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void fillRandomNumbers(int A[], int arrLen)
{
    srand(time(NULL));

    for (int i = 0; i < arrLen; ++i)
        A[i] = rand() % 100;
}