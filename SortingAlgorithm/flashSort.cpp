#include "../header.h"

using namespace std;


void flashSortCountComparisons(int*& arr, int n, long long& count_comparison) 
{
    if (++count_comparison && n <= 1) return;

    int min_val = arr[0], max_val = arr[0];
    int m = int(0.43 * n);
    vector<int> count(m, 0);

    for (int i = 1; ++count_comparison && i < n; ++i) {
        if (++count_comparison && arr[i] < min_val) min_val = arr[i];
        if (++count_comparison && arr[i] > max_val) max_val = arr[i];
    }

    if (++count_comparison && min_val == max_val) return;

    double c1 = (m - 1.0) / (max_val - min_val);
    for (int i = 0; ++count_comparison && i < n; ++i) {
        int k = int(c1 * (arr[i] - min_val));
        ++count[k];
    }

    for (int k = 1; ++count_comparison && k < m; ++k) {
        count[k] += count[k - 1];
    }

    int move = 0, j = 0, k = m - 1, t, flash;
    while (++count_comparison && move < n - 1) {
        while (++count_comparison && j > count[k] - 1) {
            ++j;
            k = int(c1 * (arr[j] - min_val));
        }
        flash = arr[j];
        while (++count_comparison && j != count[k]) {
            k = int(c1 * (flash - min_val));
            t = arr[--count[k]];
            arr[count[k]] = flash;
            flash = t;
            ++move;
        }
    }

    for (int i = 1; ++count_comparison && i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (++count_comparison && j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}


void flashSortFindRunTime(int*& arr, int n, long long& run_time) 
{
    clock_t start = clock();

    if (n <= 1) return;

    int min_val = arr[0], max_val = arr[0];
    int m = int(0.43 * n);
    vector<int> count(m, 0);

    for (int i = 1; i < n; ++i) {
        if (arr[i] < min_val) min_val = arr[i];
        if (arr[i] > max_val) max_val = arr[i];
    }

    if (min_val == max_val) return;

    double c1 = (m - 1.0) / (max_val - min_val);
    for (int i = 0; i < n; ++i) {
        int k = int(c1 * (arr[i] - min_val));
        ++count[k];
    }

    for (int k = 1; k < m; ++k) {
        count[k] += count[k - 1];
    }

    int move = 0, j = 0, k = m - 1, t, flash;
    while (move < n - 1) {
        while (j > count[k] - 1) {
            ++j;
            k = int(c1 * (arr[j] - min_val));
        }
        flash = arr[j];
        while (j != count[k]) {
            k = int(c1 * (flash - min_val));
            t = arr[--count[k]];
            arr[count[k]] = flash;
            flash = t;
            ++move;
        }
    }

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }

    clock_t end = clock();
    run_time = (long long)((end - start) * 1000 / CLOCKS_PER_SEC);
}


/*
Reference: 
https://codelearn.io/sharing/flash-sort-thuat-toan-sap-xep-than-thanh
https://en.wikipedia.org/wiki/Flashsort
https://the-algorithms.com/algorithm/flash-sort
count_comparision is done by myself
calculate runtime source code: https://stackoverflow.com/questions/11062804/measuring-the-runtime-of-a-c-code



IDEAS:
    Flash Sort (or Distribution Sort) divides the array into a number of buckets based on the distribution of elements, sorts each bucket individually, and then combines them to achieve a sorted array.

STEP BY STEP DESCRIPTION:
    1. Determine the number of buckets based on the distribution of elements in the array. Allocate space for each bucket.
    2. Distribute each element of the array into its corresponding bucket based on a calculated distribution formula.
    3. Sort each bucket individually using an efficient sorting algorithm (typically Insertion Sort due to its performance on small datasets).
    4. Combine the sorted buckets to obtain the final sorted array.

COMPLEXITY EVALUATIONS:
Let n be the number of elements in the array.

1/ Time complexity analysis:
   + Mathematics proof:
        Flash Sort's time complexity heavily depends on the distribution calculation and the sorting algorithm used for each bucket.
        - Distribution step: O(n + m), where m is the range of values.
        - Sorting step: O(n^2/k), where k is the number of buckets.
        Flash Sort achieves O(n) time complexity when properly implemented with an optimal distribution function and efficient bucket sorting.
   + Best case: O(n)
        Flash Sort can achieve linear time complexity when the distribution is uniform and the number of buckets is optimal.
   + Worst case: O(n^2)
        In the worst-case scenario, when the distribution is poor or sorting within buckets is inefficient, Flash Sort can degrade to quadratic time complexity.
   + Average case: O(n)
        On average, Flash Sort performs efficiently with linear time complexity due to its distribution and sorting steps.

2/ Space complexity analysis:
    Flash Sort is an in-place sorting algorithm, meaning it requires minimal additional space beyond the input array for bucket allocations. Its space complexity is O(n) in the worst case due to bucket allocations.

SUMMARY:
    + Advantage:
        - Efficient sorting algorithm with potential linear time complexity in optimal scenarios.
        - Particularly effective for datasets with a uniform distribution of values.
        - In-place sorting algorithm with minimal additional space requirements.
    + Disadvantage:
        - Sensitive to the distribution of values and choice of bucket count.
        - Can degrade to quadratic time complexity in unfavorable scenarios.
        - Requires careful implementation of the distribution function and bucket sorting for optimal performance.

OPTIMIZED:
    To optimize Flash Sort, focus on:
    - Designing an efficient distribution function that minimizes the spread of values among buckets.
    - Implementing an efficient sorting algorithm (like Insertion Sort) for sorting small buckets.
    - Adjusting the number of buckets based on the distribution of elements to balance sorting efficiency and memory usage.
*/




