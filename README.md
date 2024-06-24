Hi everyone, our group will have some format rules to follow when organizing the 'sorting algorithm' file.
Format:
- First Line: "include "header_file.h"
    + The file "header_file.h" will be created later whose contents is libraries in C++
- Second Line: white space
- Third Line to Nth line: the code of the function name: " 'sort_algorithm_name'CountComparision ". Ex: "void bubbleSortCountComparision(...)"
    + Of course, we can add more subfunctions
- (N+1)th Line to Kth line: the code of the function name: " 'sort_algorithm_name'FindRunTime ". Ex: "void bubbleSortFindRunTime(...)"
    + Of course, we can add more subfunctions
- (K + 1)th line to the end: all the sources that you have referred to in your code. Or you can referred that source is 'by yourself'


--------------------------------------------------------------------------------------------------------------------------------------------------------------------


Runtime function structure:

auto start = chrono::system_clock::now();

....

....

auto end = chrono::system_clock::now();

// Calculate the duration

auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

run_time = duration.count();
