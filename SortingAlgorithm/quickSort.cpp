#include "../header.h"

void quickSort(int *&arr, int left, int right)
{
    int  pi = left + (right - left) / 2; // to avoid overflow
    int pivot = arr[pi];
    int i = left;
    int j = right;
    int temp;
    while (i < j)
    {
        while (arr[i] < pivot) i++;

        while (arr[j] > pivot) j--;
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (i < right) quickSort(arr, i, right);
    if (left < j) quickSort(arr, left, j);
}

void quickSortFindRunTime(int *&arr, int n, long long &time)
{
    auto start = chrono::steady_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::steady_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void quickSortCounting(int *&arr, int left, int right, long long &count)
{
    int pi = left + (right - left) / 2; // to avoid overflow
    int pivot = arr[pi];
    int i = left;
    int j = right;
    int temp;
    while (++count && i < j)
    {
        while (++count && arr[i] < pivot)
        {
            i++;
        }
        while (++count && arr[j] > pivot)
        {
            j--;
        }
        if (++count && i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (++count && i < right) quickSortCounting(arr, i, right, count);
    if (++count && left < j) quickSortCounting(arr, left, j, count);
}

void quickSortCountComparisons(int *&arr, int n, long long &count_comparisons)
{
    count_comparisons = 0;
    quickSortCounting(arr, 0, n - 1, count_comparisons);
}


/* Note for report

Thank you Chat-GPT for helping correct grammar and algorithm commentline 

IDEAS:
    Quick Sort is a divide-and-conquer algorithm that sorts an array by selecting a pivot element and partitioning the array around the pivot 
    such that elements less than the pivot are on the left, and elements greater than the pivot are on the right. 
    This process is recursively applied to the sub-arrays formed by the partitioning.

STEP BY STEP DESCRIPTION:
    1. Select the pivot element, typically the middle element of the array.
    2. Initialize two pointers, i and j, to the start and end of the array respectively.
    3. Move the pointer i rightward until an element larger than the pivot is found.
    4. Move the pointer j leftward until an element smaller than the pivot is found.
    5. If i <= j, swap the elements at i and j, then move i and j to the next positions.
    6. Recursively apply the above steps to the sub-arrays formed by the left and right partitions.

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

REFERENCES :
    + Run time and counting comparisons is based on basic and refered to lab2 and guide of teacher Bui Huy Thong and Tran Thi Thao Nhi. 
But it does not work well so we must use chrono by chat-gpt suggest.
    + Chat-GPT: https://chatgpt.com/share/7264684e-a209-41af-bfe7-1643118ccf1b

*/
