#include "header.h"


int *readFile(string fileName, int &size)
{
    ifstream ifs(fileName);
    if(!ifs.is_open())
    {
        cout << "Cannot open input file!";
        return;
    }
    //read file
    int n;;
    ifs >> n;
    int *arr = new int[n];
    
    for(int i = 0; i < n; i++)
    {
        ifs >> arr[i]; 
    }
    ifs.close();
    return arr;
}

void writeFile(string fileName, int *arr, int n)
{
    ofstream ofs(fileName);
    ofs << n << endl;
    for(int i = 0; i < n; i++)
    {
        ofs << arr[i] << " ";
    }
    ofs.close();
}

void printOptions()
{
    cout << "Command 1: [Execution file] -a [Algorithm] [Given input] [Output parameters(s)]" << endl;
    cout << "Command 2: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameters(s)]" << endl;
    cout << "Command 3: [Execution file] -a [Algorithm] [Input size] [Output parameters(s)]" << endl;
    cout << "Command 4: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]" << endl;
    cout << "Command 5: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]" << endl;
}

void selectAlgorithm(void (*&findRunTime)(int *&, int, long long &), void (*&countComparisons)(int *&, int, long long &), string algorithmName)
{
    if (algorithmName == "bubble-sort")
    {
        countComparisons = bubbleSortCountComparisons;
        findRunTime = bubbleSortFindRunTime;
    }
    if (algorithmName == "counting-sort")
    {
        findRunTime = countingSortFindRunTime;
        countComparisons = countingSortCountComparisons;
    }
    if (algorithmName == "flash-sort")
    {
        countComparisons = flashSortCountComparisons;
        findRunTime = flashSortFindRunTime;
    }
    if (algorithmName == "heap-sort")
    {
        findRunTime = heapSortFindRunTime;
        countComparisons = heapSortCountComparisons;
    }
    if (algorithmName == "insertion-sort")
    {
        findRunTime = insertionSortFindRunTime;
        countComparisons = insertionSortCountComparisons;
    }
    if (algorithmName == "merge-sort")
    {
        findRunTime = mergeSortFindRunTime;
        countComparisons = mergeSortCountComparisons;
    }
    if (algorithmName == "quick-sort")
    {
        countComparisons = quickSortCountComparisons;
        findRunTime = quickSortFindRunTime;
    }
    if (algorithmName == "radix-sort")
    {
        countComparisons = radixSortCountComparisons;
        findRunTime = radixSortFindRunTime;
    }
    if (algorithmName == "selection-sort")
    {
        countComparisons = selectionSortCountComparisons;
        findRunTime = selectionSortFindRunTime;
    }
    if (algorithmName == "shaker-sort")
    {
        findRunTime = shakerSortFindRunTime;
        countComparisons = shakerSortCountComparisons;
    }
    if (algorithmName == "shell-sort")
    {
        findRunTime = shellSortFindRunTime;
        countComparisons = shellSortCountComparisons;
    }
}
