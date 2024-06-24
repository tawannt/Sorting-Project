#include "../header.h"



// basic Selection Sort
void selectionSort(int *&arr, int n)
{
	// selection sort algorithm: swap the cur to the min, so begin find min from cur + 1 to n, if minIdx != cur => swap them
	int i, j, min_idx; 
	for(i = 0; i < n - 1; i++) // i just need to go to arr[n - 2] because if i go to a[n - 1] it means there's only 1 element left so it's also min
	{
		min_idx = i;
		for(j = i + 1; j < n; j++)
		{
			if(arr[j] < arr[min_idx]) min_idx = j; // find minIdx
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
void selectionSortFindRunTime(int *&arr, int n, long long &time) // you can use reference int *&arr or just int *arr both of them work
{
	// start time
 	clock_t begin = clock();

	
	int i, j, min_idx; 
	for(i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for(j = i + 1; j < n; j++)
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

    // end time
	clock_t end = clock();
	
	time = (long long)((end - begin) / CLOCKS_PER_SEC * 1000); // unit is milisecond 
}

// counting comparisons
void selectionSortCountComparison(int *&arr, int n, long long &cnt_cmp)
{
	cnt_cmp = 0;

	int min_idx;
	for (int i = 0; ++cnt_cmp && i < n-1; i++)
    {
        min_idx = i;
		int j;
        for(j = i + 1; ++cnt_cmp && j < n; j++)
        {
            if(++cnt_cmp && arr[j] < arr[min_idx]) min_idx = j; 
        }
        if(++cnt_cmp && i != min_idx)
        {
            int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
        }
	}
} 



/* Note for report

Thank you Chat-GPT for helping correct grammar and algorithm commentline 

IDEAS: Selection Sort operates on the principle of repeatedly selecting the smallest (or largest) element from the unsorted part of the array and placing it in its correct position in the sorted part.
In this project, we used an iterative Selection Sort algorithm that iterates through the unsorted part of the array to find the smallest element (for ascending order) or the largest element (for descending order). 
Once the smallest (or largest) element is identified, it is swapped with the leftmost element of the unsorted part. This process is repeated until the entire array is sorted.

STEP BY STEP DESCRIPTION:
1/ Initialization:
 + i, j, and min_idx are declared to keep track of indices during the sorting process.
 + i is the index of the current element being considered for placement in the sorted portion.
 + min_idx starts at i, assuming arr[i] is the smallest element initially.
2/ Outer Loop (i-loop):
 + Iterates from i = 0 to i < n - 1. The loop runs for n-1 iterations because after n-1 iterations, the array will be sorted as the last element will naturally be in place.
3/ Inner Loop (j-loop):
 + Starts from j = i + 1 and goes up to j < n. This loop searches for the smallest element in the unsorted portion of the array (arr[i] to arr[n-1]).
 + Finding the Minimum: Within the j-loop, if (arr[j] < arr[min_idx]), checks if the current element arr[j] is smaller than arr[min_idx]. If true, min_idx is updated to j, indicating arr[j] is the new smallest element found so far in the unsorted portion.
 + Swapping Elements: After completing the j-loop, if min_idx is not equal to i, a swap occurs between arr[i] and arr[min_idx]. This places the smallest unsorted element (arr[min_idx]) into its correct position in the sorted part of the array.
4/ Repeat: 
 + The process repeats with each iteration of the outer loop (i-loop), expanding the sorted portion of the array by one element each time until the entire array is sorted. 

COMPLEXITY EVALUATIONS:
n is the number of elements in array.

1/ Time complexity analysis: 
   + Mathematics proof: 
   		i-loop: 0 to n - 2
			i = 0: j-loop 1 to n - 1 => number of comparisons: n - 1
			i = 1: j-loop 2 to n - 1 => number of comparisons: n - 2
			.....
			i = n - 2: j-loop n - 1 to n - 1 => number of comparisons: 1
			==> total comparisons: (n - 1) + (n - 2) + ... + 1 = (n - 1) * n / 2 ==> time complexity is O(n^2)
	+ Best case: O(n^2) 
		The best case occurs when the array is already sorted or nearly sorted. 
		In this scenario, even though the algorithm still iterates through the array, it performs fewer assignment (for the swap).
	+ Worst case: O(n^2)
		The worst case occurs when the array is in reverse sorted order. 
		In this scenario, the algorithm will always find the smallest element in the unsorted part and perform a swap in each iteration of the outer loop, resulting in the maximum number of comparisons and swaps.
	+ Average case: O(n^2)
		The average case assumes that the input array is randomly ordered. 
		Selection sort will perform an average number of comparisons and swaps, balancing between the best and worst case scenarios.
2/ Space complexity analysis:
	Selection sort is an in-place sorting algorithm, meaning it sorts the array without requiring additional space proportional to the size of the input array.
	=> Space complexity is O(1)

SUMMARY:
	+ Adventage:
		- Efficient for small datasets due to its simplicity and low overhead compared to more complex algorithms.
		- Simple to implement and understand. It is often used in educational contexts to introduce basic sorting concepts and to teach algorithm analysis.
	+ Disadventage:
		- Non-Stable Sorting: it may change the relative order of equal elements because it swaps non-adjacent elements.
		- Ineffecient for big datasets due to O(n^2) time complexity.
OPTIMIZED SELECTION SORT
	An improvement can be made on selection sort. As we know that the selection sort works by
	taking either the minimum or maximum element from the array and placing that element at its
	correct position. Here the idea is to take the max and min simultaneously, then sort the array
	from two ends. This is much faster than normal Selection Sort. It sorts the data in half the
	number of iterations as it sorts two data elements at a time. Therefore, it minimizes the sorting
	time by up to 50%.

REFERENCES :
	+ Basic Selection Sort is done by myself.
	+ Run time and counting comparisons is based on basic and refered to lab2 and guide of teacher Bui Huy Thong and Tran Thi Thao Nhi.
	+ Chat-GPT: https://chatgpt.com/share/57ef8d49-88f2-40d2-b7ff-8926567aa79f
	+ Slide of teacher Ngo Minh Nhut.
	+ Geeks for geeks: https://www.geeksforgeeks.org/time-and-space-complexity-analysis-of-selection-sort/?ref=lbp
	+ https://www.bethunecollege.ac.in/econtent/2021/srijoniMaitra-Computer/Srijoni-Maitra-CompSc-Q1-Selection-Sort.pdf

*/
