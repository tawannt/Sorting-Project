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

void quick_sort(int *&arr, int left, int right);
void quick_sort_run_time(int *&arr, int n, long long &time);
void quick_sort_help_count(int *&arr, int left, int right, long long &cnt);
void quick_sort_comparisons(int *&arr, int n, long long &cnt_cmp);

int get_max(int *&arr, int n);
void count_sort(int *&arr, int n, int exp);
void radix_sort(int *&arr, int n);
void radix_sort_compare(int *&arr, int n, long long &cnt_cmp);
int get_max_compare(int *&arr, int n, long long &cnt_cmp);
void count_sort_compare(int *&arr, int n, int exp, long long &cnt_cmp);
void radix_sort_run_time(int *&arr, int n, long long &time);

void selection_sort(int *&arr, int n);
void selection_sort_compare(int *&arr, int n, long long &cnt_cmp);
void selection_sort_run_time(int *&arr, int n, long long & time);

void shaker_sort(int *&arr, int n);
void shaker_sort_compare(int *&arr, int n, long long &cnt_cmp);
void shaker_sort_run_time(int *&arr, int n, long long &time);

void shellSortCompare(int *&arr, int n, long long &count_comparisons);
void shellSortRunTime(int *&arr, int n, long long &time);
#endif
