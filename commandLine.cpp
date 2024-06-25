#include "header.h"
#include "cmd.h"


int *readFile(string fileName, int &size)
{
    ifstream ifs(fileName);
    if(!ifs.is_open())
    {
        cout << "Cannot open input file!!!\n";
        return NULL;
    }

    //read file
    ifs >> size;
    int *arr = new int[size];
    
    for(int i = 0; i < size; i++)
    {
        ifs >> arr[i]; 
    }
    ifs.close();
    return arr;
}

void writeFile(string fileName, int *arr, int size)
{
    fileName = "data/" + fileName;
    ofstream ofs(fileName);
    if(!ofs.is_open())
    {
        cout << "Cannot open input file!!!\n";
        return;
    }
    ofs << size << endl;
    for(int i = 0; i < size; i++)
    {
        ofs << arr[i] << " ";
    }
    ofs.close();
}

void printOptions()
{
    cout << "Command 1: [Execution file] -a [Algorithm] [Given input] [Output parameters(s)].\n";
    cout << "Command 2: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameters(s)].\n";
    cout << "Command 3: [Execution file] -a [Algorithm] [Input size] [Output parameters(s)].\n";
    cout << "Command 4: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input].\n";
    cout << "Command 5: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order].\n";
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


void Generate(string inputOrder, int *&arr, int inputSize)
{
    if (inputOrder == "-rand")
    {
        GenerateRandomData(arr, inputSize);
    }
    else if (inputOrder == "-nsorted")
    {
        GenerateNearlySortedData(arr, inputSize);
    }
    else if (inputOrder == "-sorted")
    {
        GenerateSortedData(arr, inputSize);
    }
    else if (inputOrder == "-rev")
    {
        GenerateReverseData(arr, inputSize);
    }
}

void doForOutputParameter(void (*findRunTime)(int *&, int, long long &), void (*countComparisons)(int *&, int, long long &), int *&arr, int size, string outputParameter, long long &time, long long &count_comparison)
{
    if (outputParameter == "-time")
    {
        // Runtime
        findRunTime(arr, size, time);
    }
    else if (outputParameter == "-both")
    {
        // Runtime
        // need temp arr because after run function the array will be sort, so to ensure that before countComparison we need to reset temp arr.
        int *temp = new int[size];
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];

        findRunTime(temp, size, time);
        // Compare
        for (int i = 0; i < size; i++) //  reset
            temp[i] = arr[i];
        countComparisons(temp, size, count_comparison);
        delete[] temp;
    }
    else if (outputParameter == "-comp")
    {
        countComparisons(arr, size, count_comparison);
    }
}

void command_2(string algorithmName, int size, string inputOrder, string outputPara)
{
    // generate automatically
    int *arr = new int [size];
    Generate(inputOrder, arr, size);

    // write file
    writeFile("input.txt", arr, size);

    // run algorithm
    // firstly selectAlgorithm
    void (*findRunTime)(int *&, int, long long &) = NULL; // initialize pointer function
    void (*countComparisons)(int *&, int, long long &) = NULL;

    selectAlgorithm(findRunTime, countComparisons, algorithmName);

    if(findRunTime != NULL && countComparisons != NULL)
    {
        long long cnt_cmp = 0, time = 0;
        doForOutputParameter(findRunTime, countComparisons, arr, size, outputPara, time, cnt_cmp);
        // 3 cai if el
    }
    else 
    {
        //  bao loi 
    }


    delete[] arr;
}

void command_4(string algorithmName_1, string algorithmName_2, string filenameInput, int &size)
{
    // we need 2 the same arr like in Do function
    int *arr = readFile(filenameInput, size);
    int *arr_2 = new int [size];
    for(int i = 0; i < size; i++) arr_2[i] = arr[i];
    if(arr != NULL)
    {
        // initialize function pointer
        void (*findRunTime)(int *&, int, long long &) = NULL;
        void (*countComparisons)(int *&, int, long long &) = NULL;

        // initialize run_time_1, 2 and count_comparisons_1,2
        long long time_1 = 0, time_2 = 0, cnt_1 = 0, cnt_2 = 0; 
        // initialize = 0 just for case cannot run the program, when cout wiil not error and we will know if programe had been done or not

        // do for algorithm 1
        // find algorithm 1
        selectAlgorithm(findRunTime, countComparisons, algorithmName_1);
        if(findRunTime && countComparisons) // if algorithmName_1 is in set
        {
            doForOutputParameter(findRunTime, countComparisons, arr, size, "-both", time_1, cnt_1);
            delete[] arr;
        }
        else
        {
            cout << algorithmName_1 << " is not in set!!!\n";
            delete[] arr;
            delete[] arr_2;
            return;
        }

        // do for algorithm 2
        // reinitialize pointer function as NULL
        findRunTime = NULL;
        countComparisons = NULL;

        selectAlgorithm(findRunTime, countComparisons, algorithmName_2);
        if(findRunTime && countComparisons)
        {
            doForOutputParameter(findRunTime, countComparisons, arr_2, size, "-both", time_2, cnt_2);
            delete[] arr_2;
        }
        else
        {
            cout << algorithmName_2 << " is not in set!!!\n";
            delete[] arr_2;
            return;
        }

        cout << "COMPARE MODE\n";
        cout << "Algorithm: " << algorithmName_1 << " | " << algorithmName_2 << '\n';
        cout << "Input file: " <<  filenameInput << '\n';
        cout << "Input size: " << size << '\n'; 
        cout << "----------------------------\n";
        cout << "Running time: " << time_1 << " | " << time_2 << "  (miliseconds)\n";
        cout << "Comparisons: " << cnt_1 << " | " << cnt_2 << '\n';
    }
    else cout << "ERROR READING ARRAY FILE!!!\n";
}

void command_5(string algorithmName_1, string algorithmName_2, int size, string inputOrder)
{
    // generate arr base on order
    int *arr = new int[size];
    Generate(inputOrder, arr, size);

    // we need 2 the same arr like command_4
    int *arr_2 = new int [size];
    for(int i = 0; i < size; i++) arr_2[i] = arr[i];

    // write file
    writeFile("input.txt", arr, size);

    // initialize function pointer
    void (*findRunTime)(int *&, int, long long &) = NULL;
    void (*countComparisons)(int *&, int, long long &) = NULL;

    // initialize time 1 2 and cnt 1 2
    long long time_1 = 0, time_2 = 0, cnt_1 = 0, cnt_2 = 0;
    // do for algorithm 1
    selectAlgorithm(findRunTime, countComparisons, algorithmName_1);
    
    if(findRunTime && countComparisons)
    {
        doForOutputParameter(findRunTime, countComparisons, arr, size, "-both", time_1, cnt_1);
        delete[] arr;
    }
    else
    {
        cout << algorithmName_1 << " is not in set!!!\n";
        delete[] arr;
        delete[] arr_2;
        return;
    }

    // do for algorithm 2, do not need to delete function pointer
    findRunTime = NULL;
    countComparisons = NULL;

    selectAlgorithm(findRunTime, countComparisons, algorithmName_2);

    if(findRunTime && countComparisons)
    {
        doForOutputParameter(findRunTime, countComparisons, arr_2, size, "-both", time_2, cnt_2);
        delete[] arr_2;
    }
    else
    {
        cout << algorithmName_2 << " is not in set!!!\n";
        delete[] arr_2;
    }

    // cout 
    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << algorithmName_1 << " | " << algorithmName_2 << '\n';
    cout << "Input size: " << size << '\n';
    cout << "Input order: " << inputOrder << '\n';
    cout << "----------------------------\n";
    cout << "Running time: " << time_1 << " | " << time_2 << "  (miliseconds)\n";
    cout << "Comparisons: " << cnt_1 << " | " << cnt_2 << '\n';
}
