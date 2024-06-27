#include "../header.h"


int partition(int *&arr, int left, int right) 
{
    // Choose a pivot (median-of-three)
    int mid = left + (right - left) / 2;
    int pivot = arr[mid];

    // Move pivot to end
    swap(arr[mid], arr[right]);

    int i = left - 1; // Index of smaller element

    // Partitioning
    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    // Move pivot to its correct position
    swap(arr[i + 1], arr[right]);

    return i + 1;
}

// Recursive function to perform quicksort
void quickSort(int *&arr, int left, int right) 
{
    if (left < right) {
        // Partition the array
        int pivotIndex = partition(arr, left, right);

        // Recursively sort the left and right subarrays
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

// count comparisons
int partitionCompare(int *&arr, int left, int right, long long &cnt_cmp)
{
    // Choose a pivot (e.g., median-of-three)
    int mid = left + (right - left) / 2;
    int pivot = arr[mid];

    // Move pivot to end
    swap(arr[mid], arr[right]);

    int i = left - 1; // Index of smaller element

    // Partitioning
    for (int j = left; ++cnt_cmp && j < right; ++j) 
    {
        if (++cnt_cmp && arr[j] <= pivot) 
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    // Move pivot to its correct position
    swap(arr[i + 1], arr[right]);

    return i + 1;
}

void quickSortCounting(int *&arr, int left, int right, long long &cnt_cmp)
{
    if (++cnt_cmp && left < right) 
    {
        // Partition the array
        int pivotIndex = partitionCompare(arr, left, right, cnt_cmp);

        // Recursively sort the left and right subarrays
        quickSortCounting(arr, left, pivotIndex - 1, cnt_cmp);
        quickSortCounting(arr, pivotIndex + 1, right, cnt_cmp);
    }
}

void quickSortCountComparisons(int *&arr, int n, long long &cnt_cmp)
{
    cnt_cmp = 0;
    quickSortCounting(arr, 0, n - 1, cnt_cmp);
}

// run time
void quickSortFindRunTime(int *&arr, int n, long long &time)
{
    auto start = chrono::steady_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::steady_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

/* Note for report

Thank you Chat-GPT for helping correct grammar and algorithm commentline 

IDEAS:
    This implementation of Quick Sort uses the median-of-three pivot selection strategy and Hoare's partition scheme. Quick Sort sorts an array by selecting a pivot element and partitioning the array around the pivot such that elements less than the pivot are on the left and elements greater than the pivot are on the right. The process is then recursively applied to the sub-arrays formed by the partitioning.

STEP BY STEP DESCRIPTION:
    1. Define the partition function to select the pivot using the median-of-three method:
       - Choose the middle element as the pivot.
       - Move the pivot element to the end of the array temporarily.
       - Initialize a pointer i to track the smaller elements.
       - Iterate through the array and swap elements such that elements less than or equal to the pivot are placed to the left of i.
       - Move the pivot element to its correct position after partitioning.
    2. Implement the recursive quickSort function:
       - Partition the array using the partition function.
       - Recursively apply quickSort to the left and right sub-arrays formed by the partitioning.

COMPLEXITY EVALUATIONS:
n is the number of elements in the array.

1/ Time complexity analysis: 
   + Mathematics proof: 
   		Quick Sort involves recursively dividing the array into two halves. Each partition step takes O(n) time, and in the best and average cases, the partition divides the array roughly in half. Thus, the average time complexity is O(n log n).
	+ Best case: O(n log n)
		Occurs when the pivot selection consistently results in nearly equal partitions.
	+ Worst case: O(n^2)
		Occurs when the pivot selection consistently results in the most unbalanced partitions (e.g., smallest or largest element as pivot).
	+ Average case: O(n log n)
		In most cases, the pivot results in reasonably balanced partitions, leading to an average time complexity of O(n log n).
		
2/ Space complexity analysis:
	Space complexity is O(log n) due to the recursion stack. Each recursive call adds to the stack, and in the average case, the depth of recursion is O(log n). However, in the worst case, the recursion stack can grow to O(n).

SUMMARY:
	+ Advantage:
		- Efficient on average with O(n log n) time complexity.
		- In-place sorting algorithm with low space overhead.
		- Performs well with large datasets.
	+ Disadvantage:
		- Worst-case time complexity of O(n^2).
		- Performance heavily depends on the pivot selection.
		- Not stable; equal elements may not retain their original order.
		
OPTIMIZED:
	- Use randomization or median-of-three for pivot selection to reduce the chances of worst-case scenario.
	- Hybrid approaches like using insertion sort for small sub-arrays to improve performance.
    
REFERENCES:
    + Basic quick sort base on Hoare's quick sort: https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/
    + Run time and counting comparisons is based on basic and refered to lab2 and guide of teacher Bui Huy Thong and Tran Thi Thao Nhi. 
But clock_t does not work well so we use chrono.
    + Chat-GPT: https://chatgpt.com/share/7264684e-a209-41af-bfe7-1643118ccf1b

*/
