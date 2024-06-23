#include "header_file.h"

//subfunction
void swap(int &xp, int &yp) {
    int temp = xp;
    xp = yp;
    yp = temp;
}

//count comparisions
void bubbleSortCountComparision(int arr[], int n, long long& count_comparision)
{
    int i, j;
    bool swapped;
    for (i = 0; ++count_comparision && i < n - 1; i++) {
        swapped = false;
        for (j = 0; ++count_comparision && j < n - i - 1; j++) {
            if (++count_comparision && arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (++count_comparision && swapped == false)
            break;
    }
}

//find runtime
void bubbleSortFindRunTime(int arr[], int n, long long& run_time)
{
    auto start = chrono::system_clock::now();
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
    auto end = chrono::system_clock::now();

    // Calculate the duration
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    run_time = duration.count();
}

//REFERENCES:
//source for algorithm: https://www.geeksforgeeks.org/bubble-sort/
//count_comparision is done by myself
//calculate runtime source code: https://stackoverflow.com/questions/11062804/measuring-the-runtime-of-a-c-code
