#include <iostream>
#include <chrono>
using namespace std;

void merge(int array[], int const left, int const mid, int const right, long long& count_comparison) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
    int* leftArray = new int[subArrayOne];
    int* rightArray = new int[subArrayTwo];
    for (int i = 0; ++count_comparison && i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; ++count_comparison && j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (++count_comparison && indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (++count_comparison && leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (++count_comparison && indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (++count_comparison && indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSortCountComparison(int array[], int const begin, int const end, long long& count_comparison) {
    if (++count_comparison && begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSortCountComparison(array, begin, mid, count_comparison);
    mergeSortCountComparison(array, mid + 1, end, count_comparison);
    merge(array, begin, mid, end, count_comparison);
}

void merge(int array[], int const left, int const mid, int const right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
    int* leftArray = new int[subArrayOne];
    int* rightArray = new int[subArrayTwo];
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSortFindRunTime(int array[], int const begin, int const end, long long& run_time) {
    auto start = chrono::system_clock::now();
    if (begin >= end) {
        return;
    }
    int mid = begin + (end - begin) / 2;
    mergeSortFindRunTime(array, begin, mid, run_time);
    mergeSortFindRunTime(array, mid + 1, end, run_time);
    merge(array, begin, mid, end);
    auto end_time = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start);
    run_time += duration.count();
}

// Reference: 
//source for algorithm: https://www.geeksforgeeks.org/merge-sort/
//count_comparision is done by myself
//calculate runtime source code: https://stackoverflow.com/questions/11062804/measuring-the-runtime-of-a-c-code