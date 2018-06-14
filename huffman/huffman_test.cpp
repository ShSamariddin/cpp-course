#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <utility>
#include<fstream>
#include "huf.h"
int main(){


    huf test;
    std::ifstream inFile1;
    std::ofstream outFile1;
    inFile1.open("/home/samariddin/Desktop/test/testenc2");
    outFile1.open("/home/samariddin/Desktop/test/testdec2");
    test.encode(inFile1, outFile1);
    inFile1.close();
    outFile1.close();
    std::ifstream inFile2;
    std::ofstream outFile2;
    inFile2.open("/home/samariddin/Desktop/test/testdec2");
    outFile2.open("/home/samariddin/Desktop/test/testsec2");
    test.decode(inFile2, outFile2);
    inFile2.close();
    outFile2.close();

}

