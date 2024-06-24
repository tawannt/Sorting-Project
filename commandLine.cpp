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

void printOptions()
{
    cout << "Command 1: [Execution file] -a [Algorithm] [Given input] [Output parameters(s)]" << endl;
    cout << "Command 2: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameters(s)]" << endl;
    cout << "Command 3: [Execution file] -a [Algorithm] [Input size] [Output parameters(s)]" << endl;
    cout << "Command 4: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]" << endl;
    cout << "Command 5: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]" << endl;
}

void selectAlgorithm(void (*&findRunTime)(int *&, int, long long &), void (*&countComparisions)(int *&, int, long long &), string algorithmName)
{
    if (algorithmName == "bubble-sort")
    {
        countComparisions = bubbleSortCountComparisions;
        findRunTime = bubbleSortFindRunTime;
    }
    if (algorithmName == "counting-sort")
    {
        findRunTime = countingSortFindRunTime;
        countComparisions = countingSortCountComparisions;
    }
    if (algorithmName == "flash-sort")
    {
        countComparisions = flashSortCountComparisions;
        findRunTime = flashSortFindRunTime;
    }
    if (algorithmName == "heap-sort")
    {
        findRunTime = heapSortFindRunTime;
        countComparisions = heapSortCountComparisions;
    }
    if (algorithmName == "insertion-sort")
    {
        findRunTime = insertionSortFindRunTime;
        countComparisions = insertionSortCountComparisions;
    }
    if (algorithmName == "merge-sort")
    {
        findRunTime = mergeSortFindRunTime;
        countComparisions = mergeSortCountComparisions;
    }
    if (algorithmName == "quick-sort")
    {
        countComparisions = quickSortCountComparisions;
        findRunTime = quickSortFindRunTime;
    }
    if (algorithmName == "radix-sort")
    {
        countComparisions = radixSortCountComparisions;
        findRunTime = radixSortFindRunTime;
    }
    if (algorithmName == "selection-sort")
    {
        countComparisions = selectionSortCountComparisions;
        findRunTime = selectionSortFindRunTime;
    }
    if (algorithmName == "shaker-sort")
    {
        findRunTime = shakerSortFindRunTime;
        countComparisions = shakerSortCountComparisions;
    }
    if (algorithmName == "shell-sort")
    {
        findRunTime = shellSortFindRunTime;
        countComparisions = shellSortCountComparisions;
    }
}
