#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

template <class T>


//source for algorithm: https://www.geeksforgeeks.org/bubble-sort/
//count_comparision is done by myself
//calculate runtime source code: https://stackoverflow.com/questions/11062804/measuring-the-runtime-of-a-c-code

void swap(int &xp, int &yp) {
    int temp = xp;
    xp = yp;
    yp = temp;
}

void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

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

        // If no two elements were swapped
        // by inner loop, then break
        if (++count_comparision && swapped == false)
            break;
    }
}


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


// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
}


int main()
{
    int arr[1000];
    int n = 1000;
    GenerateRandomData(arr, n);
    long long count_comparision = 0;
    // bubbleSortCountComparision(arr, N, count_comparision);
    bubbleSortFindRunTime(arr, n, count_comparision);
    //cout << "Sorted array: \n";
    printArray(arr, n);
    cout << endl << count_comparision << endl;
    return 0;
}