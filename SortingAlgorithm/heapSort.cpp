#include "../header.h"

void heapify(int* &arr, int n, int i)
{
    int largest = i; //consider i as the root of the max heap
    
    int left = 2 * i + 1; // left child of i

    int right = 2 * i + 2; //right child of i

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;
    
    if(largest != i) //change if the largest is not the root
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); //heapify the new root
    }
}

void heapSort(int* &arr, int n)
{
    //build max heap
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]); //move the max to the end
        heapify(arr, i, 0); //reduced the heap
    }
}

void heapifyCountComparisons(int* &arr, int n, int i, long long &count_comparisons)
{
    int largest = i;
    
    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if((++count_comparisons && left < n) && (++count_comparisons && arr[left] > arr[largest]))
        largest = left;

    if((++count_comparisons && right < n) && (++count_comparisons && arr[right] > arr[largest]))
        largest = right;
    
    if(++count_comparisons && largest != i)
    {
        swap(arr[i], arr[largest]);
        heapifyCountComparisons(arr, n, largest, count_comparisons);
    }
}

void heapSortCountComparisons(int* &arr, int n, long long &count_comparisons) // comparisons not comparisions 
{
    count_comparisons = 0;
    for(int i = n/2 - 1; ++count_comparisons && i >= 0; i--)
        heapifyCountComparisons(arr, n, i, count_comparisons);

    for(int i = n - 1; ++count_comparisons && i > 0; i--)
    {
        swap(arr[i], arr[0]);
        heapifyCountComparisons(arr, i, 0, count_comparisons);
    }
}

void heapSortFindRunTime(int* &arr, int n, long long &run_time)
{
    auto start = chrono::steady_clock::now();
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }

    auto end = chrono::steady_clock::now();
    run_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}


/*
IDEAS: 
    Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure. 

STEP BY STEP DESCRIPTION:
1. Build the max heap:
    - Start from the last non-leaf node and heapify each node up to the root.
2. Extract elements one by one:
    - Swap the root (maximum element) with the last element.
    - Reduce the heap size by one and heapify the root.
    - Repeat until all elements are extracted and the array is sorted.

COMPLEXITY EVALUATIONS:
n is the number of elements in the array.

1/ Time complexity analysis:
    - Building the max heap: O(n log n)
    - Extracting elements: O(n log n)
    - Total: O(n log n)

    + Best case: O(n log n)
    + Worst case: O(n log n)
    + Average case: O(n log n)
		
2/ Space complexity analysis:
    - Space complexity is O(1) as it is an in-place sorting algorithm.

SUMMARY:
    + Advantage:
        - In-place sorting algorithm.
        - Consistent O(n log n) time complexity.
    + Disadvantage:
        - Not a stable sorting algorithm.
        - Can be slower than quicksort in practice due to cache inefficiency.

OPTIMIZED:
    - For better performance, consider using introsort, which combines quicksort and heapsort.
REFERENCE:
https://www.geeksforgeeks.org/heap-sort/
*/


