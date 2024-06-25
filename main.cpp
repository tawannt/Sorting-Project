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

int main(int argc, char** argv)
{
    if (argc != 5 && argc != 6){
        return 0;
    } else {
        string mode = argv[1];
        if (mode == "a"){
            if (argc == 5){
                if (!isNum(argv[3])){ //cmd 1:

                } else { //cmd 3

                }
            } else { //cmd 2

            }
        } else { // mode == "c"
            if (argc == 5){ //cmd 5

            } else { //cmd 6

            }
        }
    }
    return 0;
}