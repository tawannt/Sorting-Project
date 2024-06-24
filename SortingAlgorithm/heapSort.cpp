#include "../header.h"

void heapify(int *&arr, int n, int i)
{
    int largest = i; //consider i as the root of the max heap
    
    int left = 2 * i + 1; // left child of i

    int right = 2 * i + 2; //right child of i

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;
    
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *&arr, int n)
{
    //build max heap
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]); //move the max to the end
        heapify(arr, i, 0); //reduced the heap
    }
}

void heapifyCountComparisons(int *&arr, int n, int i, int &count_comparisions)
{
    int largest = i;
    
    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if((left < n && ++count_comparisions) && (arr[left] > arr[largest] && ++count_comparisions))
        largest = left;

    if((right < n && ++count_comparisions) && (arr[right] > arr[largest] && ++count_comparisions))
        largest = right;
    
    if(largest != i && ++count_comparisions)
    {
        swap(arr[i], arr[largest]);
        heapifyCountComparisons(arr, n, largest, count_comparisions);
    }
}

void heapSortCountComparison(int *&arr, int n, int &count_comparisions)
{
    count_comparisions = 0;
    for(int i = n/2 - 1; i >= 0; i--)
        heapifyCountComparisons(arr, n, i, count_comparisions);

    for(int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        heapifyCountComparisons(arr, i, 0, count_comparisions);
    }
}

void heapSortFindRunTime(int *&arr, int n, int &run_time)
{
    clock_t begin = clock();
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }

    // Calculate the duration
    clock_t end = clock();
    
    run_time = (long long)((end - begin) / CLOCKS_PER_SEC * 1000);
}


// thieu report