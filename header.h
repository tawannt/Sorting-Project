#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "DataGenerator.cpp"
using namespace std;

void bubbleSort(int* &arr, int n);
void bubbleSortCountComparisons(int* &arr, int n, long long& count_comparisons);
void bubbleSortFindRunTime(int *&arr, int n, long long &time);

void countingSort(int* &arr, int n);
void countingSortCountComparisons(int* &arr, int n, long long& count_comparisons);
void countingSortFindRunTime(int* &arr, int n, long long &run_time);

void flashSortCountComparisons(int* &arr, int n, long long& count_comparisons);
void flashSortFindRunTime(int* &arr, int n, long long& run_time) ;

void heapify(int* &arr, int n, int i);
void heapSort(int* &arr, int n);
void heapifyCountComparisons(int* &arr, int n, int i, long long &count_comparisons);
void heapSortCountComparisons(int* &arr, int n, long long &count_comparisons);
void heapSortFindRunTime(int* &arr, int n, long long &run_time);

void insertionSort(int* &arr, int n);
void insertionSortCountComparisons(int* &arr, int n, long long &count_comparisons);
void insertionSortFindRunTime(int* &arr, int n, long long &run_time);



void mergeSort(int *&arr, int left, int right);
void mergeWithComparisonCount(int* &arr, int left, int mid, int right, long long &count_comparison);
void mergeSortHelpCountComparisons(int* &arr, int n, long long &count_comparison);
void mergeSortCountComparisons(int* &arr, int n, long long &count_comparison);
void mergeArrays(int* &arr, int left, int mid, int right);
void mergeSortFindRunTime(int* &arr, int n, long long &run_time);

void quickSort(int *arr, int left, int right);
void quickSortCounting(int* &arr, int left, int right, long long &cnt);
void quickSortCountComparisons(int* &arr, int n, long long &count_comparisons);
void quickSortFindRunTime(int *&arr, int n, long long &time);

int getMax(int* &arr, int n);
void countSort(int* &arr, int n, int exp);

void radixSort(int* &arr, int n);
int getMaxCompare(int* &arr, int n, long long &cnt_cmp);
void countSortCompare(int* &arr, int n, int exp, long long &cnt_cmp);
void radixSortCountComparisons(int* &arr, int n, long long &cnt_cmp);
void radixSortFindRunTime(int* &arr, int n, long long &time);

void selectionSort(int* arr, int n);
void selectionSortFindRunTime(int* &arr, int n, long long &time);
void selectionSortCountComparisons(int* &arr, int n, long long &cnt_cmp);

void shakerSort(int* &arr, int n);
void shakerSortCountComparisons(int* &arr, int n, long long &cnt_cmp);
void shakerSortFindRunTime(int* &arr, int n, long long &time);

void shellSort(int* &arr, int n);
void shellSortCountComparisons(int* &arr, int n, long long& count_comparisons);
void shellSortFindRunTime(int* &arr, int n, long long& run_time);
#endif