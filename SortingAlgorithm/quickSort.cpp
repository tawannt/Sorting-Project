#include "../header.h"



int partition(int *&arr, int left, int right)
{
    // this code base on Hoare's quick sort
    int pivot = arr[left], i = left - 1, j = right + 1;
    while(true)
    {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);

        if(i >= j) break;

        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    return j;
}
void quickSort(int *&arr, int left, int right)
{
    if(left < right)
    {
        int p = partition(arr, left, right);
        quickSort(arr, left, p);
        quickSort(arr, p + 1, right);
    }
}

// count comparisons
int partitionCompare(int *&arr, int left, int right, long long &cnt_cmp)
{
    int pivot = arr[left], i = left - 1, j = right + 1;
    while(true)
    {
        do { i++; } while (++cnt_cmp && arr[i] < pivot);
        do { j--; } while (++cnt_cmp && arr[j] > pivot);

        if(++cnt_cmp && i >= j) break;

        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    return j;
}

void quickSortCounting(int *&arr, int left, int right, long long &cnt_cmp)
{
    if(left < right)
    {
        int p = partitionCompare(arr, left, right, cnt_cmp);
        quickSortCounting(arr, left, p, cnt_cmp);
        quickSortCounting(arr, p + 1, right, cnt_cmp);
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
    This implementation of Quick Sort is based on Hoare's partition scheme. 
    It sorts an array by selecting a pivot element and partitioning the array around the pivot such that elements less than the pivot are on the left and elements greater than the pivot are on the right. 
    The process is then recursively applied to the sub-arrays formed by the partitioning.

STEP BY STEP DESCRIPTION:
    1. Define the partition function to select the pivot and partition the array.
    2. Initialize two pointers, i starting just before the left index and j just after the right index.
    3. Move the i pointer rightward until an element greater than or equal to the pivot is found.
    4. Move the j pointer leftward until an element less than or equal to the pivot is found.
    5. If i is less than j, swap the elements at i and j, then continue the process.
    6. If i is greater than or equal to j, the partitioning is complete, and the partition function returns the index j.
    7. In the quickSort function, recursively apply the partition function to the sub-arrays to the left and right of the pivot index returned by the partition function.

COMPLEXITY EVALUATIONS:
n is the number of elements in the array.

1/ Time complexity analysis: 
   + Mathematics proof: 
   		Quick Sort involves recursively dividing the array into two halves. Each partition step takes O(n) time, and there are log(n) levels of recursion in the average case. 
        Thus, the average time complexity is O(n log n).
	+ Best case: O(n log n)
		Occurs when the pivot selection consistently results in nearly equal partitions.
	+ Worst case: O(n^2)
		Occurs when the pivot selection consistently results in the most unbalanced partitions (e.g., smallest or largest element as pivot).
	+ Average case: O(n log n)
		In most cases, the pivot results in reasonably balanced partitions, leading to an average time complexity of O(n log n).
		
2/ Space complexity analysis:
	Space complexity is O(log n) due to the recursion stack. Each recursive call adds to the stack, and in the average case, 
    the depth of recursion is O(log n). However, in the worst case, the recursion stack can grow to O(n).

SUMMARY:
	+ Advantage:
		- Efficient on average with O(n log n) time complexity.
		- In-place sorting algorithm with low space overhead.
		- Performs well with large datasets.
	+ Disadvantage:
		- Worst-case time complexity of O(n^2).
		- Performance heavily depends on the pivot selection.
		- Not stable: equal elements may not retain their original order.
		
OPTIMIZED:
	- Use randomization or median-of-three for pivot selection to reduce the chances of worst-case scenario.
	- Hybrid approaches like using insertion sort for small sub-arrays to improve performance.

REFERENCES:
    + Basic quick sort base on Hoare's quick sort: https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/
    + Run time and counting comparisons is based on basic and refered to lab2 and guide of teacher Bui Huy Thong and Tran Thi Thao Nhi. 
But it does not work well so we must use chrono by chat-gpt suggest.
    + Chat-GPT: https://chatgpt.com/share/7264684e-a209-41af-bfe7-1643118ccf1b

*/
