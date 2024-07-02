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

void insertionSortCountComparisons(int* &arr, int n, long long &count_comparisons) 
{
    count_comparisons = 0;
    int key, prev;
    for (int cur = 1; cur < n && ++count_comparisons; cur++) {
        key = arr[cur];
        prev = cur - 1;
        while (++count_comparisons && prev >= 0 && ++count_comparisons && arr[prev] > key) {
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


/*Note for report

Thank you Chat-GPT for helping correct grammar and algorithm commentline 

IDEAS: 
    The idea is to sort an array by dividing it into a sorted and an unsorted part. 
    The sorted part starts with the first element, and we repeatedly pick the next element from the unsorted part and insert it into the correct position in the sorted part.

STEP BY STEP DESCRIPTION:
1. Iterate from the second element to the last element.
2. For each element, compare it with elements in the sorted part and find its correct position.
3. Shift all elements larger than the current element to the right.
4. Insert the current element into its correct position.

COMPLEXITY EVALUATIONS:
n is the number of elements in the array.

1/ Time complexity analysis: 
   + Best case: O(n) - when the array is already sorted.
   + Worst case: O(n^2) - when the array is sorted in reverse order.
   + Average case: O(n^2)
   
2/ Space complexity analysis:
   + Space complexity is O(1) as it is an in-place sorting algorithm.

SUMMARY:
    + Advantage:
        - Simple to implement.
        - Efficient for small datasets or nearly sorted arrays.
        - Stable sorting algorithm.
    + Disadvantage:
        - Inefficient for large datasets due to O(n^2) time complexity.

OPTIMIZED 
    - For larger datasets, consider using more efficient algorithms like quicksort, mergesort, or heapsort.

REFERENCE:
https://www.geeksforgeeks.org/insertion-sort/
*/
