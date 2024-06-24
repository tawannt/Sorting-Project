#include "../header.h"


// basic shaker_sort
void shakerSort(int *&arr, int n)
{
    bool swapped = true;
    int i = 0;
    int j = n - 1;

    // continue sorting as long as swaps are happening
    while (swapped) 
    {
        swapped = false;

        // forward pass: move the largest element to the end of the unsorted part
        for (int k = i; k < j; k++) 
        {
            // compare adjacent elements and swap if they are in the wrong order
            if (arr[k] > arr[k + 1]) 
            {
                int tmp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = tmp;
                swapped = true; // swap occurred
            }
        }

        // if no swaps occurred, the array is sorted
        if (!swapped) break;

        swapped = false; // reset the swapped flag for the backward pass

        // backward pass: move the smallest element to the start of the unsorted part
        for (int k = j - 1; k > i; k--) 
        {
            // compare adjacent elements and swap if they are in the wrong order
            if (arr[k] < arr[k - 1]) 
            {
                int tmp = arr[k - 1];
                arr[k - 1] = arr[k];
                arr[k] = tmp;
                swapped = true; // swap occurred
            }
        }

        // narrow the bounds of the unsorted part
        i++;
        j--;
    }
}


// run time
void shakerSortFindRunTime(int *&arr, int n, long long &time)
{
    clock_t begin = clock();
    bool swapped = true;
    int i = 0;
    int j = n - 1;

    while (swapped) 
    {
        swapped = false;

        for (int k = i; k < j; k++) 
        {
            if (arr[k] > arr[k + 1]) 
            {
                int tmp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = tmp;
                swapped = true; 
            }
        }

        if (!swapped) break;

        swapped = false;

        for (int k = j - 1; k > i; k--) 
        {
            if (arr[k] < arr[k - 1]) 
            {
                int tmp = arr[k - 1];
                arr[k - 1] = arr[k];
                arr[k] = tmp;
                swapped = true; 
            }
        }

        i++;
        j--;
    }
    clock_t end = clock();
    time = (long long)((end - begin) / CLOCKS_PER_SEC * 1000);
}


// counting comparisons 
void shakerSortCountComparison(int *&arr, int n, long long &cnt_cmp)
{
    cnt_cmp = 0;
    bool swapped = true;
    int i = 0;
    int j = n - 1;

    while (++cnt_cmp && swapped == true)
    {
        swapped = false;

        for(int k = i; ++cnt_cmp && k < j; k++)
        {
            if(++cnt_cmp && arr[k] > arr[k + 1])
            {
                int tmp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = tmp;
                swapped = true;
            }
        }

        if(++cnt_cmp && swapped == false) break;

        swapped = false;
        for(int k = j - 1; k > i; k--)
        {
            if(++cnt_cmp && arr[k] < arr[k - 1])
            {
                int tmp = arr[k];
                arr[k] = arr[k - 1];
                arr[k - 1] = tmp;
                swapped = true;
            }
        }

        i++;
        j--;
    }
}


/* Note for report

Thank you Chat-GPT for helping correct grammar and algorithm commentline 

IDEAS:
    Shaker Sort, also known as Cocktail Shaker Sort or Bidirectional Bubble Sort, is a variation of Bubble Sort. 
    It sorts the array by moving elements in both directions, first from left to right and then from right to left, 
    effectively narrowing the bounds of the unsorted section from both ends.

STEP BY STEP DESCRIPTION:
    1. Initialize the swapped flag to true to enter the sorting loop.
    2. Perform a forward pass, moving the largest unsorted element to the end of the unsorted section.
    3. If any swaps occur, set the swapped flag to true; otherwise, break the loop.
    4. Perform a backward pass, moving the smallest unsorted element to the beginning of the unsorted section.
    5. If any swaps occur, set the swapped flag to true.
    6. Narrow the bounds of the unsorted section by incrementing the starting index and decrementing the ending index.
    7. Repeat steps 2-6 until no swaps occur during a complete pass.

COMPLEXITY EVALUATIONS:
n is the number of elements in the array.

1/ Time complexity analysis: 
   + Mathematics proof: 
   		Shaker Sort performs n-1 comparisons and swaps in each direction (forward and backward) for each iteration. 
        The number of iterations is approximately n/2. Thus, in the worst case, the time complexity is O(n^2).
	+ Best case: O(n)
		Occurs when the array is already sorted, and only one forward and backward pass is needed without any swaps.
	+ Worst case: O(n^2)
		Occurs when the array is sorted in reverse order, requiring the maximum number of swaps and passes.
	+ Average case: O(n^2)
		In most cases, the number of passes and comparisons is proportional to n^2.
		
2/ Space complexity analysis:
	Space complexity is O(1) as the sorting is done in place without requiring additional memory, except for a few temporary variables.

SUMMARY:
	+ Advantage:
		- Simple to understand and implement.
		- More efficient than Bubble Sort for partially sorted arrays.
		- Stable sort; equal elements retain their relative order.
	+ Disadvantage:
		- Inefficient for large arrays due to O(n^2) time complexity.
		- Not suitable for performance-critical applications.
		
OPTIMIZED:
	- Introduce a flag to track the last swapped position, reducing the bounds of the unsorted section more effectively.
	- Combine with other sorting algorithms for better performance on larger datasets.
-
REFERENCES:
    + Basic Shaker Sort is refered to geeks for geeks: https://www.geeksforgeeks.org/cocktail-sort/
    + Run time and counting comparisons is based on basic and refered to lab2 and guide of teacher Bui Huy Thong and Tran Thi Thao Nhi.
    + Chat-GPT: https://chatgpt.com/share/7264684e-a209-41af-bfe7-1643118ccf1b
*/