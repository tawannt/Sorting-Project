#include "../header.h"

void insertionSort(int* &arr, int n)
{
    int key, prev;
    for (int cur = 1; cur < n; cur++) {
        key = arr[cur];
        prev = cur - 1;
        while (prev >= 0 && arr[prev] > key) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = key;
    }
}

void insertionSortCountComparisons(int* &arr, int n, long long &count_comparisons) // comparisons not comparisions 
{
    count_comparisons = 0;
    int key, prev;
    for (int cur = 1; cur < n && ++count_comparisons; cur++) {
        key = arr[cur];
        prev = cur - 1;
        while (++count_comparisons && arr[prev] > key && ++count_comparisons && arr[prev] > key) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = key;
    }
}

void insertionSortFindRunTime(int* &arr, int n, long long &run_time)
{
    auto start = chrono::steady_clock::now();
    int key, prev;
    for (int cur = 1; cur < n; cur++) {
        key = arr[cur];
        prev = cur - 1;
        while (prev >= 0 && arr[prev] > key) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = key;
    }
    auto end = chrono::steady_clock::now();
    run_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
