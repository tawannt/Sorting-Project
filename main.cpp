#include "header.h"
#include "cmd.h"

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
    if (argc != 5 && argc != 6){
        printOptions();
        return 0;
    } else {
        // const char* as the same as string !?
        string algorithmName_1, algorithmName_2, outputParameter, inputOrder, fileInput;
        int size;
        string mode = argv[1];
        if (mode == "-a"){
            if (argc == 5){
                if (!isNum(argv[3])){ //cmd 1:

                } else { //cmd 3

                }
            } else { //cmd 2

            }
        } 
        else 
        { // mode == "c"
            if (argc == 5)
            { //cmd 4
                algorithmName_1 = argv[2];
                algorithmName_2 = argv[3];
                fileInput = argv[4];
                command_4(argv[2], argv[3], argv[4], size);
            } 
            else 
            { 
                //cmd 5
                algorithmName_1 = argv[2];
                algorithmName_2 = argv[3];
                size = stoi(argv[4]);
                inputOrder = argv[5];
                command_5(algorithmName_1, algorithmName_2, size, inputOrder);
            }
        }
    }
    return 0;
}