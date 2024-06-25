#include "../header.h"


void merge(int*& arr, int const left, int const mid, int const right, long long& count_comparison) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

    for (int i = 0; ++count_comparison && i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; ++count_comparison && j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (++count_comparison && indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (++count_comparison && leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (++count_comparison && indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (++count_comparison && indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

//  ham nay cung can coi lai nhu ham findruntime nha doi lai tham so dau vao int *&, int , long long& nha
void mergeSortCountComparisons(int*& arr, int const begin, int const end, long long& count_comparison) {
    if (++count_comparison && begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSortCountComparisons(arr, begin, mid, count_comparison);
    mergeSortCountComparisons(arr, mid + 1, end, count_comparison);
    merge(arr, begin, mid, end, count_comparison);
}


// khuc nay o dat ten ham trung voi ham o dong 4 lun, nguy hiem qua
void merge(int*& arr, int const left, int const mid, int const right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

// ko dung ham nay duoc nha o, o chinh lai mergeSortFindRunTime(int *&a, int n, long long &run_time) thi moi dung format dc nha
// suggest la o viet 1 ham merge binh thuong, xong trong ham find run time thi o cho no chan o dau o cuoi thoi, xem thu quickSort nha
void mergeSortFindRunTime(int*& arr, int const begin, int const end, long long& run_time) {
    clock_t start = clock();
    if (begin >= end) {
        run_time = (long long)((clock() - start) * 1000 / CLOCKS_PER_SEC);
        return;
    }

    int mid = begin + (end - begin) / 2;
    mergeSortFindRunTime(arr, begin, mid, run_time);
    mergeSortFindRunTime(arr, mid + 1, end, run_time);
    merge(arr, begin, mid, end);

    
    run_time = (long long)((clock() - start) * 1000 / CLOCKS_PER_SEC);
}



/*
Reference:
https://www.geeksforgeeks.org/merge-sort/
count_comparision is done by myself
calculate runtime source code: https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
algorithm description:
     Book:Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein Introduction to Algorithms, Third Edition  2009 (page 30->39)
    + https://en.wikipedia.org/wiki/Merge_sort
    + ChatGPT.

IDEAS:
    Merge Sort divides the array into halves recursively until each sub-array contains only one element. It then merges these sub-arrays back together in sorted order.

STEP BY STEP DESCRIPTION:
    1. Divide the array into two halves recursively until each sub-array contains only one element.
    2. Merge the sub-arrays back together in sorted order:
       - Compare the elements of the two sub-arrays, one by one.
       - Place the smaller (or larger) element into the original array, and move to the next element in the respective sub-array.
       - Repeat until all elements are merged back into a single sorted array.

COMPLEXITY EVALUATIONS:
Let n be the number of elements in the array.

1/ Time complexity analysis:
   + Mathematics proof:
        Merge Sort consistently divides the array into halves, making log2(n) divisions. Each division requires merging the sorted sub-arrays, which takes linear time. Thus, the time complexity is O(n log n).
   + Best case: O(n log n)
        Merge Sort's performance is consistent regardless of input data. It always divides the array into halves and merges them efficiently.
   + Worst case: O(n log n)
        Even in the worst-case scenario, Merge Sort divides the array into halves and merges them, resulting in the same time complexity.
   + Average case: O(n log n)
        Merge Sort maintains O(n log n) time complexity on average due to its consistent division and merging process.

2/ Space complexity analysis:
    Merge Sort requires additional space proportional to the size of the input array for storing temporary sub-arrays during the merge process. Thus, its space complexity is O(n) in the worst case.

SUMMARY:
    + Advantage:
        - Efficient and stable sorting algorithm with O(n log n) time complexity in all cases.
        - Suitable for large datasets and practical applications due to its consistent performance.
        - Guarantees sorting with O(n) additional space complexity for temporary arrays.
    + Disadvantage:
        - Requires additional space for merging sub-arrays, making it less optimal for memory-constrained environments.
        - More complex to implement compared to simpler algorithms like Bubble Sort.

OPTIMIZED:
    For optimal performance, utilize Merge Sort when a stable, efficient sorting algorithm is required, especially for large datasets. Consider optimizations such as tail recursion elimination or iterative implementations to reduce stack usage.
*/
