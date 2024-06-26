#include "../header.h"

// basic
void selectionSort(int *&arr, int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		int min_idx = i;
		for(int j = i + 1; j < n; j++)
		{
			if(arr[j] < arr[min_idx]) min_idx = j; 
		}
		if(min_idx != i)
		{
			int tmp = arr[min_idx];
			arr[min_idx] = arr[i];
			arr[i] = tmp;
		}
	}
}
// run Time  
void selectionSortFindRunTime(int* &arr, int n, long long &time) // you can use reference int *&arr or just int *arr both of them work
{
	// start time
 	auto start = chrono::steady_clock::now();
	selectionSort(arr, n);
    // end time
	auto end = chrono::steady_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// counting comparisons
void selectionSortCountComparisons(int* &arr, int n, long long &cnt_cmp)
{
	cnt_cmp = 0;
	for (int i = 0; ++cnt_cmp && i < n-1; i++)
    {
        int min_idx = i;
        for(int j = i + 1; ++cnt_cmp && j < n; j++)
        {
            if(++cnt_cmp && arr[j] < arr[min_idx]) min_idx = j; 
        }
        if(++cnt_cmp && i != min_idx)
        {
            int tmp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = tmp;
        }
	}
} 

/* Note for report

Thank you Chat-GPT for helping correct grammar and algorithm commentline 

IDEAS:
    Selection Sort is a simple comparison-based sorting algorithm. It sorts an array by repeatedly finding the minimum element from the unsorted portion and placing it at the beginning. This process is repeated for each position in the array until the entire array is sorted.

STEP BY STEP DESCRIPTION:
    1. Iterate over each element in the array from the first to the second-to-last position (index i).
    2. For each position i, assume the element at index i is the smallest (initialize min_idx to i).
    3. Iterate through the rest of the array (from index i+1 to n-1) to find the actual smallest element.
    4. If a smaller element is found, update min_idx to the index of this element.
    5. After finding the smallest element in the unsorted portion, if min_idx is different from i, swap the element at i with the element at min_idx.
    6. Repeat the process for the next position in the array.

COMPLEXITY EVALUATIONS:
n is the number of elements in the array.

1/ Time complexity analysis:
   + Mathematics proof:
   		Selection Sort has two nested loops: the outer loop runs n-1 times and the inner loop runs (n-i-1) times on average. Thus, the time complexity is O(n^2).
	+ Best case: O(n^2)
		Occurs when the array is already sorted; still needs to perform all comparisons.
	+ Worst case: O(n^2)
		Occurs when the array is sorted in reverse order; needs to perform all comparisons and swaps.
	+ Average case: O(n^2)
		Involves performing n/2 swaps on average, resulting in O(n^2) time complexity.
		
2/ Space complexity analysis:
	Space complexity is O(1) as it is an in-place sorting algorithm

REFERENCES :
	+ Run time and counting comparisons is based on basic and refered to lab2 and guide of teacher Bui Huy Thong and Tran Thi Thao Nhi.
But clock_t does not work well so we use chrono.
	+ Chat-GPT: https://chatgpt.com/share/57ef8d49-88f2-40d2-b7ff-8926567aa79f
	+ Slide of teacher Ngo Minh Nhut.
	+ Geeks for geeks: https://www.geeksforgeeks.org/time-and-space-complexity-analysis-of-selection-sort/?ref=lbp
	+ https://www.bethunecollege.ac.in/econtent/2021/srijoniMaitra-Computer/Srijoni-Maitra-CompSc-Q1-Selection-Sort.pdf

*/
