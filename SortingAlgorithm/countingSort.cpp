#include "../header.h"

void countingSort(int* &arr, int n)
{
    int maxElement = arr[0];
    int minElement = arr[0];

    //find max, min
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > maxElement) maxElement = arr[i];
        if(arr[i] < minElement) minElement = arr[i];
    }
    //create count array and save the original array
    int *count = new int[maxElement - minElement + 1];
    for(int i = 0; i < maxElement - minElement + 1; i++) count[i] = 0;
    int *tmp = new int[n]; 
    //count the frequency of elements
    for(int i = 0; i < n; i++)
    {
        count[arr[i] - minElement]++;
        tmp[i] = arr[i];
    }
    //prefix sum
    for(int i = 1; i < maxElement - minElement + 1; i++)
    {
        count[i] += count[i - 1];
    }
    //use tmp and count to make the output array
    for(int i = n - 1; i >= 0; i--)
    {
        arr[count[tmp[i]] - 1] = tmp[i];
        count[tmp[i]]--;
    }   
    delete[] count;
    delete[] tmp;
}

void countingSortCountComparisons(int* &arr, int n, long long& count_comparisons)
{
    count_comparisons = 0;

    int maxElement = arr[0];
    int minElement = arr[0];

    
    for(int i = 1; i < n && ++count_comparisons; i++)
    {
        if(arr[i] > maxElement && ++count_comparisons) maxElement = arr[i];
        if(arr[i] < minElement && ++count_comparisons) minElement = arr[i];
    }
    
    int *count = new int[maxElement - minElement + 1];
    for(int i = 0; i < maxElement - minElement + 1 && ++count_comparisons; i++) count[i] = 0;
    int *tmp = new int[n]; 
    
    for(int i = 0; i < n && ++count_comparisons; i++)
    {
        count[arr[i] - minElement]++;
        tmp[i] = arr[i];
    }
    
    for(int i = 1; i < maxElement - minElement + 1 && ++count_comparisons; i++)
    {
        count[i] += count[i - 1];
    }
    
    for(int i = n - 1; i >= 0 && ++count_comparisons; i--)
    {
        arr[count[tmp[i]] - 1] = tmp[i];
        count[tmp[i]]--;
    }   
    delete[] count;
    delete[] tmp;
}

void countingSortFindRunTime(int* &arr, int n, long long &run_time)
{
    clock_t begin = clock();

    int maxElement = arr[0];
    int minElement = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > maxElement) maxElement = arr[i];
        if(arr[i] < minElement) minElement = arr[i];
    }
    
    int *count = new int[maxElement - minElement + 1];
    for(int i = 0; i < maxElement - minElement + 1; i++) count[i] = 0;
    int *tmp = new int[n]; 
    
    for(int i = 0; i < n; i++)
    {
        count[arr[i] - minElement]++;
        tmp[i] = arr[i];
    }
    
    for(int i = 1; i < maxElement - minElement + 1; i++)
    {
        count[i] += count[i - 1];
    }
    
    for(int i = n - 1; i >= 0; i--)
    {
        arr[count[tmp[i]] - 1] = tmp[i];
        count[tmp[i]]--;
    }   
    delete[] count;
    delete[] tmp;

    clock_t end = clock();
    run_time = (long long)((end - begin) / CLOCKS_PER_SEC * 1000);
}
