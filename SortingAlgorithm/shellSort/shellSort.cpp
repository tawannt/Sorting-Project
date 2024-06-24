#include "./header.h"

//count comparisions
void shellSortCountComparisions(int* &arr, int n, long long& count_comparisions)
{
    for (int gap = n / 2; ++count_comparisions && gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; ++count_comparisions && i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; ++++count_comparisions && j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}

//find runtime
void shellSortFindRunTime(int* &arr, int n, long long& run_time)
{
    clock_t begin = clock();
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    clock_t end = clock();
    run_time = (long long)(end - begin);
}

//REFERENCES:
//source for algorithm: https://www.geeksforgeeks.org/shellsort/
//count_comparision is done by myself
//calculate runtime source code: https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
//algorithm description: 
    // + https://www.geeksforgeeks.org/shellsort/
    // + 
    // + 
    // + ChatGPT: https://chatgpt.com/share/0bca8e4a-3f08-4dea-a477-6e1e679fe277

// IDEAS: 
//     Shell Sort is a generalized version of the Insertion Sort algorithm. The idea is to arrange the list of elements so that, starting anywhere, taking every hth element produces a sorted list. Such a list is said to be h-sorted. The algorithm uses a sequence of gaps (which decrease over iterations) to perform gapped insertion sort.

// STEP BY STEP DESCRIPTION:
//     1. Start with a large gap (n / 2), where n is the number of elements in the array.
//     2. Perform a gapped insertion sort for the current gap.
//         a. For each element in the array starting from the gap, compare it with the element at the current position minus the gap.
//         b. If the current element is smaller than the element at the current position minus the gap, swap them.
//         c. Continue this process until the correct position for the current element is found.
//     3. Reduce the gap by half and repeat step 2.
//     4. Continue reducing the gap and performing gapped insertion sort until the gap is 1.
//     5. When the gap is 1, perform a final insertion sort to fully sort the array.

// COMPLEXITY EVALUATIONS:
// Let n be the number of elements in array.

// 1/ Time complexity analysis: 
//    + Mathematics proof: 
//         The time complexity of Shell Sort depends on the gap sequence. In the worst case, the number of comparisons can be shown to be O(n^2). However, with a good gap sequence (like the Knuth sequence), the time complexity can be significantly improved. Empirical results show that Shell Sort performs much better than O(n^2) on average.
// 	+ Best case: O(n log n)
// 		The best case occurs when the array is already sorted, and the algorithm performs the minimum number of comparisons.
// 	+ Worst case: O(n^2)
// 		The worst case occurs when the elements are arranged in reverse order or have a specific structure that makes the algorithm perform the maximum number of comparisons.
// 	+ Average case: O(n^1.5)
// 		Empirical evidence suggests that the average case time complexity is around O(n^1.5) with a good gap sequence.

// 2/ Space complexity analysis:
// 	The space complexity of Shell Sort is O(1) because it is an in-place sorting algorithm. It only requires a constant amount of additional memory space for variables.

// SUMMARY:
// 	+ Advantage:
// 		- Shell Sort is simple to understand and implement.
// 		- It is more efficient than Insertion Sort for larger lists.
// 		- It performs well for medium-sized arrays and has good average-case performance.
// 		- It requires minimal additional memory (in-place sorting).
// 	+ Disadvantage:
// 		- The time complexity in the worst case is not as good as more advanced algorithms like Quick Sort, Merge Sort, or Heap Sort.
// 		- The performance heavily depends on the choice of the gap sequence, which can be tricky to determine.
		
// OPTIMIZED:
// 	- Use an efficient gap sequence like the Hibbard sequence or Sedgewick sequence to improve performance.
// 	- Experiment with different gap sequences to find the one that works best for the specific data set being sorted.
