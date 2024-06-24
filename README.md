Hi everyone, our group will have some format rules to follow when organizing the 'sorting algorithm' file.
Format:
- First Line: #include "header.h"
    + The file "header.h" will be created later whose contents is libraries in C++
- Second Line: white space
- Third Line to Nth line: the code of the function name: " 'sort_algorithm_name'CountComparision ". Ex: "void bubbleSortCountComparision(...)"
    + Of course, we can add more subfunctions
- (N+1)th Line to Kth line: the code of the function name: " 'sort_algorithm_name'FindRunTime ". Ex: "void bubbleSortFindRunTime(...)"
    + Of course, we can add more subfunctions
- (K + 1)th line to the end: all the sources that you have referred to in your code. Or you can referred that source is 'by yourself'


--------------------------------------------------------------------------------------------------------------------------------------------------------------------


Runtime function structure:

clock_t begin = clock();

....
....


clock_t end = clock();

time = (long long)(end - begin);
