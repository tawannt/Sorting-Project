#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void flashSortCountComparison(int arr[], int n, long long& count_comparison) {
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

void flashSortFindRunTime(int arr[], int n, long long& run_time) {
    auto start = chrono::system_clock::now();

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

    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    run_time = duration.count();
}
// Reference: 
//https://codelearn.io/sharing/flash-sort-thuat-toan-sap-xep-than-thanh
//https://the-algorithms.com/algorithm/flash-sort
//count_comparision is done by myself
//calculate runtime source code: https://stackoverflow.com/questions/11062804/measuring-the-runtime-of-a-c-code
