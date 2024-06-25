#include "./header.h"

// subfunction
void swap(int &xp, int &yp) 
{
    int temp = xp;
    xp = yp;
    yp = temp;
}

void bubbleSort(int* &arr, int n)
{
    // forget to firstly assign count_comparisons = 0;
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

// count comparisions
void bubbleSortCountComparisons(int* &arr, int n, long long& count_comparisions)
{
    // forget to firstly assign count_comparisons = 0;
    int i, j;
    bool swapped;
    for (i = 0; ++count_comparisions && i < n - 1; i++) {
        swapped = false;
        for (j = 0; ++count_comparisions && j < n - i - 1; j++) {
            if (++count_comparisions && arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (++count_comparisions && swapped == false)
            break;
    }
}

// find runtime
void bubbleSortFindRunTime(int* &arr, int n, long long& run_time)
{
    clock_t begin = clock();
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }

    clock_t end = clock();

    run_time = (long long)((end - begin) / CLOCKS_PER_SEC * 1000);
}

/*
REFERENCES:
source for algorithm: https://www.geeksforgeeks.org/bubble-sort/
count_comparision is done by myself
calculate runtime source code: https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
algorithm description: 
    + https://ijirt.org/master/publishedpaper/IJIRT142753_PAPER.pdf
    + https://aissmspoly.org.in/wp-content/uploads/2020/01/Searching-and-Sorting.pdf
    + https://www.geeksforgeeks.org/bubble-sort/
    + ChatGPT.

IDEAS:
    The Bubble Sort algorithm iteratively steps over the list, compares nearby members, and swaps them if they are out of order. Until the list is sorted, these steps are repeated. In the event that the list is sorted before all iterations are finished, an optimisation is built in to stop the algorithm.

STEP BY STEP DESCRIPTION:
    1. Initialize a variable 'i' for running a loop over the entire list or array
    2. A boolean flag called "swapped" should be set to false before the inner loop begins.
    3. Start the inner loop with a variable 'j' iterating from 0 to n - i - 1.
    4. Compare the current element 'arr[j]' with the next element 'arr[j + 1]' in the array.
    5. If 'arr[j]' is greater than 'arr[j + 1]', swap them and set 'swapped' to true.
    6. After the inner loop completes, check if 'swapped' is false.
    7. If 'swapped' equals to false, that means no elements were swapped and the array is sorted, stop the execution.
    8. Else, repeat the process until the array is sorted or early termination.

COMPLEXITY EVALUATIONS:
Let n be the number of elements in the array.

1/ Time complexity analysis: 
   + Mathematics proof: 
        In each iteration of the outer loop, the largest unsorted element "bubbles up" to its correct position. In the worst case, the algorithm performs a total of 'n * (n - 1) / 2' comparisons.
   + Best case: O(n)
        The best case occurs when the array is already sorted. The algorithm will only make one pass through the array, performing n-1 comparisons and detecting that no swaps are needed.
   + Worst case: O(n^2)
        The worst case occurs when the array is sorted in reverse order. The algorithm will perform the maximum number of comparisons and swaps.
   + Average case: O(n^2)
        On average, the algorithm will performs quadratic time complexity due to the nested loops.

2/ Space complexity analysis:
    Because Bubble Sort only needs a fixed amount of additional space for variables "i," "j," and "swapped," regardless of the size of the input, its space complexity is O(1).

SUMMARY:
    + Advantage:
        - Simple to understand and implement.
        - Performs well on small or nearly sorted datasets.
        - In-place sorting algorithm with O(1) additional space. Therefore, this one is good to use when limiting the memory space.
    + Disadvantage:
        - With O(n^2) time complexity in the average and worst case, the algorithm isn't inefficient for a list containing a huge number of items.
        - The bubble sort works best in academic settings; it is not appropriate for practical uses..

OPTIMIZED:
    To optimize, consider using more efficient sorting algorithms like Quick Sort or Merge Sort, which have better average and worst-case time complexities. 
    If using Bubble Sort, ensure to include the early termination check to improve performance on nearly sorted arrays.
*/