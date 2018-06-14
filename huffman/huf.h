#ifndef HUF_H
#define HUF_H
# include<fstream>
# include<vector>
#include <iostream>

class huf
{
public:
    const int blocksize = 128000;
    void clear();
    void encode(std::ifstream& inFile, std::ofstream& outFile);
    void decode(std::ifstream& inFile, std::ofstream& outFile);
    huf();
};

#endif // HUF_H
