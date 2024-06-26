#include "header.h"
#include "SortingAlgorithm/bubbleSort.cpp"
#include "SortingAlgorithm/countingSort.cpp"
#include "SortingAlgorithm/flashSort.cpp"
#include "SortingAlgorithm/heapSort.cpp"
#include "SortingAlgorithm/insertionSort.cpp"
#include "SortingAlgorithm/mergeSort.cpp"
#include "SortingAlgorithm/quickSort.cpp"
#include "SortingAlgorithm/radixSort.cpp"
#include "SortingAlgorithm/selectionSort.cpp"
#include "SortingAlgorithm/shakerSort.cpp"
#include "SortingAlgorithm/shellSort.cpp"
#include "commandLine.cpp"

bool isNum(string str){
    for (int i = 0; i < str.length(); i++){
        if (!(str[i] >= 48 && str[i] <= 57)) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char *argv[])
{
    if (argc != 5 && argc != 6)
    {
        printOptions();
        return 0;
    } 
    else 
    {
        // const char* as the same as string ?!
        string algorithmName_1, algorithmName_2, outputParameter, inputOrder, fileInput;
        int size;
        string mode = argv[1];

        if (mode == "-a")
        {
            if (argc == 5)
            {
                if (!isNum(argv[3]))
                {
                    algorithmName_1 = argv[2];
                    fileInput = argv[3];
                    outputParameter = argv[4];
                    command_1(algorithmName_1, fileInput, outputParameter);
                }
                else 
                { 
                    algorithmName_1 = argv[2];
                    size = atoi(argv[3]);
                    outputParameter = argv[4];
                    command_3(algorithmName_1, size, outputParameter);
                }
            } 
            else 
            { 
                algorithmName_1 = argv[2];
                size = atoi(argv[3]);
                inputOrder = argv[4];
                outputParameter = argv[5];
                command_2(algorithmName_1, size, inputOrder, outputParameter);
            }
        } 
        else 
        { 
            // mode == "c"
            if (argc == 5)
            { 
                //cmd 4
                algorithmName_1 = argv[2];
                algorithmName_2 = argv[3];
                fileInput = argv[4];
                command_4(algorithmName_1, algorithmName_2, fileInput, size);
            } 
            else 
            { 
                //cmd 5
                algorithmName_1 = argv[2];
                algorithmName_2 = argv[3];
                size = atoi(argv[4]);
                inputOrder = argv[5];
                command_5(algorithmName_1, algorithmName_2, size, inputOrder);
            }
        }
    }
    std::cout << '\n';
    system("pause");
    std::cout << '\n';
    return 0;
}

/*
this main function is written to experiments base on lab3 guid (page 1)

int main()
{
    string data_order[4] = {"-rand", "-nsorted", "-sorted", "-rev"};
    int data_size[6] = {10000, 30000, 50000, 100000, 300000, 500000};
    string algorithms_name[11] = {"bubble-sort", "counting-sort", "flash-sort", "heap-sort", "insertion-sort", "merge-sort", "quick-sort", "radix-sort", "selection-sort", "shaker-sort", "shell-sort"};
    for(int i = 0; i < 4; i++)
    {
        cout << data_order[i] << '\n';

        for(int j = 0; j < 6; j++)
        {
            cout << "Data size: " << data_size[j] << '\n';

            // generate arr
            int *a = new int[data_size[j]];
            int *tmp = new int[data_size[j]]; //need tmp to sort
            int *tmp2 = new int[data_size[j]];
            Generate(data_order[i], a, data_size[j]);

            for(int k = 0; k < 11; k++)
            {
                // reset tmp like the origin arr
                for(int h = 0; h < data_size[j]; h++) 
                {
                    tmp[h] = a[h];
                    tmp2[h] = a[h];
                }

                cout << algorithms_name[k] << '\n';

                
                void (*findRunTime)(int *&, int, long long &) = NULL;
                void (*countComparisons)(int *&, int, long long &) = NULL;
                long long time = -1, cnt = 0;

                // choose algorithm
                selectAlgorithm(findRunTime, countComparisons, algorithms_name[k]);
                findRunTime(tmp, data_size[j], time);
                countComparisons(tmp2, data_size[j], cnt);
                cout << "Running time: " << time << '\n';
                cout << "Comparisons: " << cnt << '\n';
                cout << "---------------------------\n";
                cout << '\n';
                
            }
            delete[] a;
            delete[] tmp;
            delete[] tmp2;
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
*/