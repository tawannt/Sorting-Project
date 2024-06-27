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
    ofstream ofs(fileName);
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
        // Run time
        // need temp arr because after run function the array will be sort, so to ensure that before countComparison we need to reset temp arr.
        int *temp = new int[size];
        for (int i = 0; i < size; i++) temp[i] = arr[i];

        findRunTime(temp, size, time);
        delete[] temp;
        // Compare
        countComparisons(arr, size, count_comparison);
    }
    else if (outputParameter == "-comp")
    {
        countComparisons(arr, size, count_comparison);
    }
    else cout << "WRONG OUTPUTPARAMETERS!!!\n";
}

void command_1(string algorithmName, string inputFileName, string outputParameter)
{
    int size;
    long long runTime = -1, comparisons = 0;
    int* arr = readFile(inputFileName, size);
    if (arr != NULL)
    {
        // select function
        void (*findRunTime)(int*&, int, long long&) = NULL;
        void (*countComparisons)(int*&, int, long long&) = NULL;
        selectAlgorithm(findRunTime, countComparisons, algorithmName);

        if (findRunTime && countComparisons)
        {
            // print information
            cout << "ALGORITHM MODE\n";
            cout << "Algorithm: " << algorithmName << endl;
            cout << "Input file: " << inputFileName << endl;
            cout << "Input size: " << size << endl;
            cout << "--------------------------\n";

            // present running time and comparisons
            doForOutputParameter(findRunTime, countComparisons, arr, size, outputParameter, runTime, comparisons);
            if(runTime >= 0) cout << "Running time: " << runTime << " (miliseconds)\n";
            if(comparisons > 0) cout << "Comparisons: " << comparisons << '\n';

            // write file
            writeFile("output.txt", arr, size);
        }
        else cout << "ALGORITHM IS NOT IN SET!!!\n";
        delete[] arr;
    }
    else cout << "ERROR READING FILE!!!\n";
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

    long long cnt_cmp = 0, time = -1;

    if(findRunTime != NULL && countComparisons != NULL)
    {
        doForOutputParameter(findRunTime, countComparisons, arr, size, outputPara, time, cnt_cmp);

        // cout 
        string tmp;
        if(inputOrder == "-rand") tmp = "Randomized Data";
        if(inputOrder == "-nsorted") tmp = "Nearly Sorted Data";
        if(inputOrder == "-sorted") tmp = "Sorted Data";
        if(inputOrder == "-rev") tmp = "Reverse Sorted Data";

        string tmp2;
        if(algorithmName == "bubble-sort") tmp2 = "Bubble Sort";
        if(algorithmName == "counting-sort") tmp2 = "Counting Sort";
        if(algorithmName == "flash-sort") tmp2 = "Flash Sort";
        if(algorithmName == "heap-sort") tmp2 = "Heap Sort";
        if(algorithmName == "insertion-sort") tmp2 = "Insertion Sort";
        if(algorithmName == "merge-sort") tmp2 = "Merge Sort";
        if(algorithmName == "quick-sort") tmp2 = "Quick Sort";
        if(algorithmName == "radix-sort") tmp2 = "Radix Sort";
        if(algorithmName == "selection-sort") tmp2 = "Selection Sort";
        if(algorithmName == "shaker-sort") tmp2 = "Shaker Sort";
        if(algorithmName == "shell-sort") tmp2 = "Shell Sort"; 

        cout << "ALGORITHM MODE\n";
        cout << "Algorithm: " << tmp2 << '\n';
        cout << "Input size: " << size << '\n';
        cout << "Input order: " << tmp << '\n';
        cout << "----------------------------\n";
        if(time >= 0) cout << "Running time: " << time << '\n';
        if(cnt_cmp > 2) cout << "Comparisons:" << cnt_cmp << '\n';
    }
    else  
    {
        cout << "ERROR TO FIND FUNCTION!!!\n"; 
    }

    delete[] arr;
}

void command_3(string algorithmName, int size, string outputPara)
{
    // initialize 
    int *arr = new int[size];
    long long time = -1, cnt_cmp = 0;

    // 
    void (*findRunTime)(int *&, int, long long &) = NULL;
    void (*countComparisons)(int *&, int, long long &) = NULL;
    selectAlgorithm(findRunTime, countComparisons, algorithmName);

    if (findRunTime != NULL && countComparisons != NULL)
    {
        string tmp;
        if(algorithmName == "bubble-sort") tmp = "Bubble Sort";
        if(algorithmName == "counting-sort") tmp = "Counting Sort";
        if(algorithmName == "flash-sort") tmp = "Flash Sort";
        if(algorithmName == "heap-sort") tmp = "Heap Sort";
        if(algorithmName == "insertion-sort") tmp = "Insertion Sort";
        if(algorithmName == "merge-sort") tmp = "Merge Sort";
        if(algorithmName == "quick-sort") tmp = "Quick Sort";
        if(algorithmName == "radix-sort") tmp = "Radix Sort";
        if(algorithmName == "selection-sort") tmp = "Selection Sort";
        if(algorithmName == "shaker-sort") tmp = "Shaker Sort";
        if(algorithmName == "shell-sort") tmp = "Shell Sort";

        cout << "ALGORITHM MODE\n";
        cout << "Algorithm: " << tmp << '\n';
        cout << "Input size: " << size << '\n';
        cout << '\n';

        // Random order
        Generate("-rand", arr, size);
        writeFile("input_1.txt", arr, size);
        doForOutputParameter(findRunTime, countComparisons, arr, size, outputPara, time, cnt_cmp);
        cout << "Input order: Randomized\n";
        cout << "----------------------------\n";
        if (outputPara == "-time" || outputPara == "-both")
            cout << "Running time: " << time << " milliseconds\n";
        if (outputPara == "-comp" || outputPara == "-both")
            cout << "Comparisons: " << cnt_cmp << '\n';

        cout << '\n';

        // Nearly sorted order
        Generate("-nsorted", arr, size);
        writeFile("input_2.txt", arr, size);
        doForOutputParameter(findRunTime, countComparisons, arr, size, outputPara, time, cnt_cmp);
        cout << "Input order: Nearly Sorted\n";
        cout << "----------------------------\n";
        if (outputPara == "-time" || outputPara == "-both")
            cout << "Running time: " << time << " milliseconds\n";
        if (outputPara == "-comp" || outputPara == "-both")
            cout << "Comparisons: " << cnt_cmp << '\n';
        
        cout << '\n';

        // Sorted order
        Generate("-sorted", arr, size);
        writeFile("input_3.txt", arr, size);
        doForOutputParameter(findRunTime, countComparisons, arr, size, outputPara, time, cnt_cmp);
        cout << "Input order: Sorted\n";
        cout << "----------------------------\n";
        if (outputPara == "-time" || outputPara == "-both")
            cout << "Running time: " << time << " milliseconds\n";
        if (outputPara == "-comp" || outputPara == "-both")
            cout << "Comparisons: " << cnt_cmp << '\n';
        
        cout << '\n';

        // Reverse sorted order
        Generate("-rev", arr, size);
        writeFile("input_4.txt", arr, size);
        doForOutputParameter(findRunTime, countComparisons, arr, size, outputPara, time, cnt_cmp);
        cout << "Input order: Reversed\n";
        cout << "----------------------------\n";
        if (outputPara == "-time" || outputPara == "-both")
            cout << "Running time: " << time << " milliseconds\n";
        if (outputPara == "-comp" || outputPara == "-both")
            cout << "Comparisons: " << cnt_cmp << '\n';
        
        cout << '\n';
    }
    else
    {
        cout << "ERROR TO FIND FUNCTION!!!\n";
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
    long long time_1 = -1, time_2 = -1, cnt_1 = 0, cnt_2 = 0;

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
    string tmp;
    if(inputOrder == "-rand") tmp = "randomized data";
    if(inputOrder == "-nsorted") tmp = "nearly sorted data";
    if(inputOrder == "-sorted") tmp = "sorted data";
    if(inputOrder == "-rev") tmp = "reverse sorted data";

    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << algorithmName_1 << " | " << algorithmName_2 << '\n';
    cout << "Input size: " << size << '\n';
    cout << "Input order: " << tmp << '\n';
    cout << "----------------------------\n";
    cout << "Running time: " << time_1 << " | " << time_2 << "  (miliseconds)\n";
    cout << "Comparisons: " << cnt_1 << " | " << cnt_2 << '\n';
}
