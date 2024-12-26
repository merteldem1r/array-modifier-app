#include <sorting_methods.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils.h>

void InsertionSort(int A[], size_t arrLen) {
    for (int i = 1; i < arrLen; ++i) {
        const int key = A[i];
        int j = i - 1;

        while (j >= 0 && key < A[j]) {
            A[j + 1] = A[j];
            --j;
        }

        A[j + 1] = key;
    }
}

void ShellSort(int A[], int32_t arrLen) {
    for (int gap = arrLen / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < arrLen; ++i) {
            const int32_t temp = A[i];
            int32_t j;

            for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
                A[j] = A[j - gap];

            A[j] = temp;
        }
    }
}

//  i        j
// [1,2,3,4  5,6,7,8]
//  l     m        h
void merge(int A[], int32_t low, int32_t mid, int32_t high) {
    const size_t tempLen = high - low + 1;
    int32_t *temp = (int32_t *) malloc(tempLen * sizeof(int32_t));
    int32_t k = 0, i = low, j = mid + 1;

    if (temp == NULL) {
        printConsoleMessage(0, "Memory allocation for Merge Sort failed");
        exit(1);
    }

    while (i <= mid && j <= high) {
        if (A[i] < A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    for (; i <= mid; ++i)
        temp[k++] = A[i];
    for (; j <= high; ++j)
        temp[k++] = A[j];

    k = low;
    for (int p = 0; p < tempLen && k <= high; ++p)
        A[k++] = temp[p];

    free(temp);
}

void MergeSort(int A[], int32_t low, int32_t high) {
    if (low >= high) return;

    const int32_t mid = low + (high - low) / 2;
    MergeSort(A, low, mid);
    MergeSort(A, mid + 1, high);
    merge(A, low, mid, high);
}

int partition(int A[], int32_t low, int32_t high) {
    const int32_t pivotIdx = low + rand() % (high - low + 1);
    const int32_t pivotVal = A[pivotIdx];

    swap(&A[pivotIdx], &A[high]);
    int32_t i = low;
    for (int j = low; j < high; ++j) {
        if (A[j] < pivotVal) {
            swap(&A[i], &A[j]);
            ++i;
        }
    }

    swap(&A[i], &A[high]);
    return i;
}

void QuickSort(int A[], int32_t low, int32_t high) {
    if (low >= high) return;

    const int32_t pivotIdx = partition(A, low, high);
    QuickSort(A, low, pivotIdx - 1);
    QuickSort(A, pivotIdx + 1, high);
}
