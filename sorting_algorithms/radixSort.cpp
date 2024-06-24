#include "../header.h"

int getMax(int *&arr, int n)
{
    int max_val = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max_val) max_val = arr[i];
    }
    return max_val;
}

void countSort(int *&arr, int n, int exp)
{
    int *output = new int[n]; // Allocate memory for the output array dynamically
    int count_digit[10] = {0}; // Array to store count of occurrences of digits

    // Count the occurrences of each digit in the given digit place (exp)
    for (int i = 0; i < n; i++) count_digit[(arr[i] / exp) % 10]++;

    // Change countdigit so that it contains actual positions of digits in output[]
    for (int i = 1; i < 10; i++) count_digit[i] += count_digit[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) 
    {
        output[count_digit[(arr[i] / exp) % 10] - 1] = arr[i];
        count_digit[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers
    for (int i = 0; i < n; i++) arr[i] = output[i];

    delete[] output; // Free the dynamically allocated memory
}


// basic radix_sort
void radixSort(int *&arr, int n)
{
    // Find the maximum number to know the number of digits
    int max_val = getMax(arr, n);

    // Do count sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is the current digit number
    for(int exp = 1; max_val / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}


// count run time
void radixSortFindRunTime(int *&arr, int n, long long &time)
{
    clock_t begin = clock();

    int max_val = getMax(arr, n);

    for(int exp = 1; max_val / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }

    clock_t end = clock();

    time = (long long)(end - begin);
}


// count comparisons 
int getMaxCompare(int *&arr, int n, long long &cnt_cmp)
{
    int max_val = arr[0];
    
    for(int i = 1; ++cnt_cmp && i < n; i++)
    {
        if(++cnt_cmp && arr[i] > max_val) max_val = arr[i];
    }
    return max_val;
}

void countSortCompare(int *&arr, int n, int exp, long long &cnt_cmp)
{
    int *output = new int [n];
    int count_digit[10] = {0};

    for (int i = 0; ++cnt_cmp && i < n; i++) count_digit[(arr[i] / exp) % 10]++;

    for (int i = 1; ++cnt_cmp && i < 10; i++) count_digit[i] += count_digit[i - 1];

    for (int i = n - 1; ++cnt_cmp && i >= 0; i--) 
    {
        output[count_digit[(arr[i] / exp) % 10] - 1] = arr[i];
        count_digit[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; ++cnt_cmp && i < n; i++) arr[i] = output[i];

    delete[] output;
}

void radixSortCountComparison(int *&arr, int n, long long &cnt_cmp)
{
    cnt_cmp = 0;
    int max_val = getMaxCompare(arr, n, cnt_cmp);

    for(int exp = 1; ++cnt_cmp && max_val / exp > 0; exp *= 10)
    {
        countSortCompare(arr, n, exp, cnt_cmp);
    }
}


/* Note for report

Thank you Chat-GPT for helping correct grammar and algorithm commentline 

IDEAS:
    Radix Sort is a non-comparative sorting algorithm that sorts numbers by processing individual digits. 
    It sorts the numbers digit by digit, starting from the least significant digit to the most significant digit using a stable counting sort as a subroutine.

STEP BY STEP DESCRIPTION:
    1. Find the maximum value in the array to determine the number of digits in the largest number.
    2. For each digit position (from least significant to most significant), perform a counting sort based on that digit.
    3. In counting sort, count the occurrences of each digit and calculate the cumulative counts to determine the positions in the output array.
    4. Build the output array by placing elements in their correct positions based on the current digit.
    5. Copy the sorted elements from the output array back to the original array.
    6. Repeat the process for the next significant digit until all digits are processed.

COMPLEXITY EVALUATIONS:
n is the number of elements in the array.

1/ Time complexity analysis: 
   + Mathematics proof: 
   		Radix Sort processes each digit separately, and each pass involves a counting sort which takes O(n) time. 
        If d is the number of digits in the largest number, the total time complexity is O(d * n).
	+ Best case: O(d * n)
		Occurs when the elements are uniformly distributed.
	+ Worst case: O(d * n)
		Occurs regardless of the initial order of elements.
	+ Average case: O(d * n)
		Average case also has the same complexity as it processes each digit for all elements.
		
2/ Space complexity analysis:
	Space complexity is O(n + k), where n is the number of elements in the array and k is the range of the digit (0-9). 
    This includes the output array and the count array used in counting sort.

SUMMARY:
	+ Advantage:
		- Linear time complexity for fixed digit size.
		- Efficient for sorting large numbers with a fixed number of digits.
		- Stable sorting algorithm, preserves the relative order of equal elements.
	+ Disadvantage:
		- Requires additional space for the output and count arrays.
		- Not suitable for sorting data types that cannot be easily represented as sequences of digits.
		- Performance depends on the number of digits in the largest number.
		
OPTIMIZED:
	- Use a more efficient subroutine like bucket sort or MSD Radix Sort for different types of input data.
	- Combine with other sorting algorithms for specific data distributions to improve performance.


REFERENCES:
    + Basic Radix Sort is refer to slide of teacher Ngo Minh Nhut and Chat-GPT.
    + Run time and counting comparisons is based on basic and refered to lab2 and guide of teacher Bui Huy Thong and Tran Thi Thao Nhi.
    + Chat-GPT: https://chatgpt.com/share/7264684e-a209-41af-bfe7-1643118ccf1b

*/

