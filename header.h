#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "DataGenerator.cpp"
using namespace std;

void bubbleSortCompare(int *&arr, int n, long long &count_comparisons);
void bubbleSortRunTime(int *&arr, int n, long long &time);

void countingSortCompare(int *&arr, int n, long long &count_comparisons);
void countingSortRunTime(int *&arr, int n, long long &time);

void insertionSort(int *arr, int n);
void flashSortRunTime(int *&arr, int n, long long &time);
void insertionSortCompare_1(int *arr, int n, long long &count_comparisons);
void flashSortCompare(int *&arr, int n, long long &count_comparisons);

void heapify(int *&arr, int n, int i);
void heapSortRunTime(int *&arr, int n, long long &time);
void heapifyCompare(int *&arr, int n, int i, long long &count_comparisons);
void heapSortCompare(int *&arr, int n, long long &count_comparisons);

void insertionSortCompare(int *&arr, int n, long long &count_comparisons);
void insertionSortRunTime(int *&arr, int n, long long &time);

void merge(int*&arr, int l, int m, int r);
void mergeSort(int*& arr, int l, int r);
void mergeSortRunTime(int *&arr, int n, long long &time);
void mergeCount(int *arr, int l, int m, int r, long long &count);
void mergeSortCount(int*& arr, int l, int r, long long &count);
void mergeSortCompare(int *&arr, int n, long long &count_comparisons);

void quickSort(int *arr, int left, int right);
void quickSortRunTime(int *&arr, int n, long long &time);
void quickSortCounting(int *&arr, int left, int right, long long &count);
void quickSortCompare(int *&arr, int n, long long &count_comparisons);

int getMax(int *&arr, int n);
void countSort(int *&arr, int n, int exp);
void radixSortCompare(int *&arr, int n, long long &count_comparisons);
int getMaxCompare(int *&arr, int n, long long &count_comparisons);
void countSortCompare(int *&arr, int n, int exp, long long &count_comparisons);
void radixSortRunTime(int *&arr, int n, long long &time);

void selectionSortCompare(int *&arr, int n, long long &count_comparisons);
void selection_sort_run_time(int *&arr, int n, long long &time);

void shakerSortCompare(int *&arr, int n, long long &count_comparisons);
void shakerSortRunTime(int *&arr, int n, long long &time);

void shellSortCompare(int *&arr, int n, long long &count_comparisons);
void shellSortRunTime(int *&arr, int n, long long &time);
#endif
