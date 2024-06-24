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

void bubbleSortCountComparisons(int* &arr, int n, long long& count_comparisions);
void bubbleSortFindRunTime(int *&arr, int n, long long &time);

void countingSortCountComparisons(int *&arr, int n, long long &count_comparisons);
void countingSortFindRunTime(int *&arr, int n, long long &time);


void flashSortRunTime(int *&arr, int n, long long &time);
void insertionSortCompare_1(int *arr, int n, long long &count_comparisons);
void flashSortCompare(int *&arr, int n, long long &count_comparisons);

void heapify(int *&arr, int n, int i);
void heapSortRunTime(int *&arr, int n, long long &time);
void heapifyCompare(int *&arr, int n, int i, long long &count_comparisons);
void heapSortCompare(int *&arr, int n, long long &count_comparisons);

void insertionSort(int *arr, int n);
void insertionSortCompare(int *&arr, int n, long long &count_comparisons);
void insertionSortRunTime(int *&arr, int n, long long &time);

void merge(int*&arr, int l, int m, int r);
void mergeSort(int*& arr, int l, int r);
void mergeSortRunTime(int *&arr, int n, long long &time);
void mergeCount(int *arr, int l, int m, int r, long long &count);
void mergeSortCount(int*& arr, int l, int r, long long &count);
void mergeSortCompare(int *&arr, int n, long long &count_comparisons);

void quickSort(int *&arr, int left, int right);
void quickSortFindRunTime(int *&arr, int n, long long &time);
void quickSortHelpCount(int *&arr, int left, int right, long long &cnt);
void quickSortCountComparisons(int *&arr, int n, long long &cnt_cmp);

int getMax(int *&arr, int n);
void countSort(int *&arr, int n, int exp);
void radixSort(int *&arr, int n);
void radixSortCountComparisons(int *&arr, int n, long long &cnt_cmp);
int getMaxCompare(int *&arr, int n, long long &cnt_cmp);
void countSortCompare(int *&arr, int n, int exp, long long &cnt_cmp); 
void radixSortFindRunTime(int *&arr, int n, long long &time);

void selectionSort(int *&arr, int n);
void selectionSortCountComparisons(int *&arr, int n, long long &cnt_cmp);
void selectionSortFindRunTime(int *&arr, int n, long long &time);

void shakerSort(int *&arr, int n);
void shakerSortCountComparisons(int *&arr, int n, long long &cnt_cmp); 
void shakerSortFindRunTime(int *&arr, int n, long long &time);

void shellSortCompare(int *&arr, int n, long long &count_comparisons);
void shellSortRunTime(int *&arr, int n, long long &time);
#endif