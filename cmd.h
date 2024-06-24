#include "header.h"

void printOptions();
int *readFile(string fileName, int &size);
void writeFile(string fileName, int *arr, int n);
void selectAlgorithm(void (*&findRunTime)(int *&, int, long long &), void (*&countComparisions)(int *&, int, long long &), string algorithmName);
