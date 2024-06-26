#include "../header.h"

void countingSort(int* &arr, int n)
{
    int maxElement = arr[0];
    int minElement = arr[0];

    // Find max, min
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > maxElement) maxElement = arr[i];
        if(arr[i] < minElement) minElement = arr[i];
    }

    // Create count array and save the original array
    int range = maxElement - minElement + 1;
    int *count = new int[range]();
    int *tmp = new int[n];

    // Count the frequency of elements
    for(int i = 0; i < n; i++)
    {
        count[arr[i] - minElement]++;
        tmp[i] = arr[i];
    }

    // Prefix sum
    for(int i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }

    // Use tmp and count to make the output array
    for(int i = n - 1; i >= 0; i--)
    {
        arr[--count[tmp[i] - minElement]] = tmp[i];
    }

    delete[] count;
    delete[] tmp;
}

void countingSortCountComparisons(int* &arr, int n, long long& count_comparisons)
{
    count_comparisons = 0;

    int maxElement = arr[0];
    int minElement = arr[0];

    for(int i = 1; i < n && ++count_comparisons; i++)
    {
        if(arr[i] > maxElement && ++count_comparisons) maxElement = arr[i];
        if(arr[i] < minElement && ++count_comparisons) minElement = arr[i];
    }

    int range = maxElement - minElement + 1;
    int *count = new int[range]();
    int *tmp = new int[n];

    for(int i = 0; i < n && ++count_comparisons; i++)
    {
        count[arr[i] - minElement]++;
        tmp[i] = arr[i];
    }

    for(int i = 1; i < range && ++count_comparisons; i++)
    {
        count[i] += count[i - 1];
    }

    for(int i = n - 1; i >= 0 && ++count_comparisons; i--)
    {
        arr[--count[tmp[i] - minElement]] = tmp[i];
    }

    delete[] count;
    delete[] tmp;
}

void countingSortFindRunTime(int* &arr, int n, long long &run_time)
{
    auto start = chrono::steady_clock::now();

    int maxElement = arr[0];
    int minElement = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > maxElement) maxElement = arr[i];
        if(arr[i] < minElement) minElement = arr[i];
    }

    int range = maxElement - minElement + 1;
    int *count = new int[range]();
    int *tmp = new int[n];

    for(int i = 0; i < n; i++)
    {
        count[arr[i] - minElement]++;
        tmp[i] = arr[i];
    }

    for(int i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }

    for(int i = n - 1; i >= 0; i--)
    {
        arr[--count[tmp[i] - minElement]] = tmp[i];
    }

    delete[] count;
    delete[] tmp;

    auto end = chrono::steady_clock::now();
    run_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

/*
IDEAS: 
    The idea is to count the frequency of each distinct element in the input array 
    and use that information to place the elements in their correct sorted positions.
STEP BY STEP DESCRIPTION:
1. Find the minimum and maximum elements in the array.
2. Create a count array to store the frequency of each unique element.
3. Populate the count array with the frequency of each element.
4. Modify the count array to store the cumulative sum of the counts.
5. Use the count array and the original array to place elements into their correct positions.
6. Copy the sorted elements back into the original array.

COMPLEXITY EVALUATIONS:
n is the number of elements in the array.
k is the range of input data (maxElement - minElement + 1).

1/ Time complexity analysis: 
   + Finding min and max elements: O(n)
   + Populating the count array: O(n)
   + Modifying the count array: O(k)
   + Constructing the output array: O(n)
   + Copying the sorted elements: O(n)
   
   Therefore, the total time complexity is O(n + k).
   
   + Best case: O(n + k)
   + Worst case: O(n + k)
   + Average case: O(n + k)
   
2/ Space complexity analysis:
   + Count array: O(k)
   + Temporary array: O(n)
   
   Therefore, the total space complexity is O(n + k).

SUMMARY:
    + Advantage:
        - Efficient for sorting arrays with a limited range of integers.
        - Stable sorting algorithm.
    + Disadvantage:
        - Requires extra space proportional to the range of the input data.
        - Not suitable for large range values.

OPTIMIZED 
    - For large range values, consider other sorting algorithms such as quicksort, mergesort, or heapsort.

REFERENCE
https://www.geeksforgeeks.org/counting-sort/
*/
