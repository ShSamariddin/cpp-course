#include <gtest/gtest.h>
# include <bits/stdc++.h>
# include "huf.h"
# include "huffman.h"

bool cheker(std::ifstream& ans1, std::ifstream& ans2){
    const int blocksize = 10;
    std::unique_ptr<uint8_t[]> data1(new uint8_t[blocksize]);
    std::unique_ptr<uint8_t[]> data2(new uint8_t[blocksize]);
    while (!ans1.eof() && !ans2.eof()){

        ans1.read((char*) (data1.get()), blocksize);
        ans2.read((char*) (data2.get()), blocksize);
        if(ans1.gcount() != ans2.gcount()){
            return 0;
        }
        if(ans1.gcount() == 0){
            continue;
        }
        std::string t1((char *) data1.get(), (char *) data1.get() + ans1.gcount());//= (char*)data1.get();
        std::string t2((char *) data2.get(), (char *) data2.get() + ans2.gcount());// = (char*) data2.get();
        if(t1 != t2){
            return 0;
        }
    }
    if(!ans1.eof() || !ans2.eof()){
        return 0;
    }
    return 1;
}

TEST(correctness, test2) {
    huf test;
    std::ifstream inFile1;
    std::ofstream outFile1;
    inFile1.open("/home/samariddin/Documents/cpp-course/huffman/test/testenc1");
    outFile1.open("/home/samariddin/Documents/cpp-course/huffman/test/testdec1");
    test.encode(inFile1, outFile1);
    inFile1.close();
    outFile1.close();
    std::ifstream inFile2;
    std::ofstream outFile2;
    inFile2.open("/home/samariddin/Documents/cpp-course/huffman/test/testdec1");
    outFile2.open("/home/samariddin/Documents/cpp-course/huffman/test/testsec1");
    test.decode(inFile2, outFile2);
    inFile2.close();
    outFile2.close();
    std::ifstream ans1;
    std::ifstream ans2;
    ans1.open("/home/samariddin/Documents/cpp-course/huffman/test/testenc1");
    ans2.open("/home/samariddin/Documents/cpp-course/huffman/test/testsec1");
    EXPECT_TRUE(cheker(ans1, ans2));
    ans1.close();
    ans2.close();

}
TEST(correctness, test1){
	huf test;
    std::ifstream inFile1;
    std::ofstream outFile1;
    inFile1.open("/home/samariddin/Documents/cpp-course/huffman/test/testenc1");
    outFile1.open("/home/samariddin/Documents/cpp-course/huffman/test/testdec1");
    test.encode(inFile1, outFile1);
    inFile1.close();
    outFile1.close();
    std::ifstream inFile2;
    std::ofstream outFile2;
    inFile2.open("/home/samariddin/Documents/cpp-course/huffman/test/testdec1");
    outFile2.open("/home/samariddin/Documents/cpp-course/huffman/test/testsec1");
    test.decode(inFile2, outFile2);
    inFile2.close();
    outFile2.close();
    std::ifstream ans1;
    std::ifstream ans2;
    ans1.open("/home/samariddin/Documents/cpp-course/huffman/test/testenc1");
    ans2.open("/home/samariddin/Documents/cpp-course/huffman/test/testsec1");
    EXPECT_TRUE(cheker(ans1, ans2));
    ans1.close();
    ans2.close();
}
TEST(correctness, test3){
    huf test;
    std::ifstream inFile1;
    std::ofstream outFile1;
    inFile1.open("/home/samariddin/Documents/cpp-course/huffman/test/testenc3");
    outFile1.open("/home/samariddin/Documents/cpp-course/huffman/test/testdec3");
    test.encode(inFile1, outFile1);
    inFile1.close();
    outFile1.close();
    std::ifstream inFile2;
    std::ofstream outFile2;
    inFile2.open("/home/samariddin/Documents/cpp-course/huffman/test/testdec3");
    outFile2.open("/home/samariddin/Documents/cpp-course/huffman/test/testsec3");
    test.decode(inFile2, outFile2);
    inFile2.close();
    outFile2.close();
    std::ifstream ans1;
    std::ifstream ans2;
    ans1.open("/home/samariddin/Documents/cpp-course/huffman/test/testenc3");
    ans2.open("/home/samariddin/Documents/cpp-course/huffman/test/testsec3");
    EXPECT_TRUE(cheker(ans1, ans2));
    ans1.close();
    ans2.close();
}

TEST(correctness ,test4){
    std::ofstream text;
    text.open("/home/samariddin/Documents/cpp-course/huffman/test/testenc4");
    int t = rand() % 100000;
    while(t != 0){
        t--;
        uint8_t siz = rand() % 256;
        text.write((char *) &(siz), sizeof(int32_t));
    }
    text.close();
    huf test;
    std::ifstream inFile1;
    std::ofstream outFile1;
    inFile1.open("/home/samariddin/Documents/cpp-course/huffman/test/testenc4");
    outFile1.open("/home/samariddin/Documents/cpp-course/huffman/test/testdec4");
    test.encode(inFile1, outFile1);
    inFile1.close();
    outFile1.close();
    std::ifstream inFile2;
    std::ofstream outFile2;
    inFile2.open("/home/samariddin/Documents/cpp-course/huffman/test/testdec4");
    outFile2.open("/home/samariddin/Documents/cpp-course/huffman/test/testsec4");
    test.decode(inFile2, outFile2);
    inFile2.close();
    outFile2.close();
    std::ifstream ans1;
    std::ifstream ans2;
    ans1.open("/home/samariddin/Documents/cpp-course/huffman/test/testenc4");
    ans2.open("/home/samariddin/Documents/cpp-course/huffman/test/testsec4");
    EXPECT_TRUE(cheker(ans1, ans2));
    ans1.close();
    ans2.close();
}
