#include "header.h"

void printOptions();
int *readFile(string fileName, int &size);
void writeFile(string fileName, int *arr, int size);
void selectAlgorithm(void (*&findRunTime)(int *&, int, long long &), void (*&countComparisons)(int *&, int, long long &), string algorithmName);
void Generate(string inputOrder, int *&arr, int inputSize);
void Analysis(void (*findRunTime)(int *&, int, long long &), void (*countComparisons)(int *&, int, long long &), int *&arr, int size, string output_parameter, long long &time, long long &count_comparison)