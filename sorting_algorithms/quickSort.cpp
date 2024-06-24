#include "header.h"




// basic Quick Sort
void quickSort(int *&arr, int left, int right) 
{
    int pivot = arr[(left + right) / 2];  // pivot selection mid
    int i = left;
    int j = right;
    
    while (i <= j) // main partitioning loop
    {  
        while (arr[i] < pivot) i++; // move i right past smaller elements
        while (arr[j] > pivot) j--; // move j left past larger elements
        
        if (i <= j) 
        {  // swap elements if i and j haven't crossed
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    
    if (left < j) quickSort(arr, left, j); // recur for left partition
    if (i < right) quickSort(arr, i, right);  // recur for right partition
}


// run time
void quickSortFindRunTime(int *&arr, int n, long long &time)
{
    clock_t begin = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    time = (long long)(end - begin);
}


// counting comparisons 
void quickSortHelpCount(int *&arr, int left, int right, long long &cnt)
{
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while(++cnt && i <= j)
    {
        while(++cnt && arr[i] < pivot) i++;
        while(++cnt && arr[j] > pivot) j++;

        if(++cnt && i <= j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    }

    if(left < j) quickSortHelpCount(arr, left, j, cnt);
    if(right > i) quickSortHelpCount(arr, i, right, cnt);
}

void quickSortCountComparison(int *&arr, int n, long long &cnt_cmp)
{
    cnt_cmp = 0;
    quickSortHelpCount(arr, 0, n - 1, cnt_cmp);
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
    + Basic Quick Sort is refer to my teammate.
    + Run time and counting comparisons is based on basic and refered to lab2 and guide of teacher Bui Huy Thong and Tran Thi Thao Nhi.
    + Chat-GPT: https://chatgpt.com/share/7264684e-a209-41af-bfe7-1643118ccf1b

*/

