#include <iostream>

using namespace std;

int main(int argc, char** args)
{
    if(argc != 4){
       throw runtime_error("arguments");
    }
    ifstream read;
    ofstream write;
    string s = args[1];

    if(s == "encod"){
        read.open(args[2]);
        write.open(args[3]);
        if(read.fail() || write.fail()){
            throw runtime_error("wrong direction");
        }
    }
}

