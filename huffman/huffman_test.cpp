//#include <algorithm>
//#include <cassert>
//#include <cstdlib>
//#include <vector>
//#include <bits/stdc++.h>
//#include<fstream>
//#include "huf.h"

//bool cheker(std::ifstream& ans1, std::ifstream& ans2){
//    const int blocksize = 10;
//    std::unique_ptr<uint8_t[]> data1(new uint8_t[blocksize]);
//    std::unique_ptr<uint8_t[]> data2(new uint8_t[blocksize]);
//    while (!ans1.eof() && !ans2.eof()){

//        ans1.read((char*) (data1.get()), blocksize);
//        ans2.read((char*) (data2.get()), blocksize);
//        if(ans1.gcount() != ans2.gcount()){
//            return 0;
//        }
//        std::string t1 = (char*)data1.get();
//        std::string t2 = (char*) data2.get();
//        if(t1 != t2){
//            return 0;
//        }
//    }
//    if(!ans1.eof() || !ans2.eof()){
//        return 0;
//    }
//    return 1;
//}

//int main(){


//    // huf test;
//    // std::ifstream inFile1;
//    // std::ofstream outFile1;
//    // inFile1.open("./test/testenc1");
//    // outFile1.open("./test/testdec1");
//    // test.encode(inFile1, outFile1);
//    // inFile1.close();
//    // outFile1.close();
//    // std::ifstream inFile2;
//    // std::ofstream outFile2;
//    // inFile2.open("../test/testdec1");
//    // outFile2.open("../test/testsec1");
//    // test.decode(inFile2, outFile2);
//    // inFile2.close();
//    // outFile2.close();
//    // std::ifstream ans1;
//    // std::ifstream ans2;
//    // ans1.open("../test/testenc1");
//    // ans2.open("../test/testsec1");
//    // if(cheker(ans1, ans2)){
//    //     std::cout <<"YES\n";
//    // } else{
//    //     std::cout <<"NO\n";
//    // }
//    // ans1.close();
//    // ans2.close();

//    // huf text;
//    // inFile1.open("/home/samariddin/Documents/cpp-course/huffman/test/testenc2");
//    // outFile1.open("/home/samariddin/Documents/cpp-course/huffman/test/testdec2");
//    // text.encode(inFile1, outFile1);
//    // inFile1.close();
//    // outFile1.close();
//    // inFile2.open("/home/samariddin/Documents/cpp-course/huffman/test/testdec2");
//    // outFile2.open("/home/samariddin/Documents/cpp-course/huffman/test/testsec2");
//    // text.decode(inFile2, outFile2);
//    // inFile2.close();
//    // outFile2.close();
//    // ans1.open("/home/samariddin/Documents/cpp-course/huffman/test/testenc2");
//    // ans2.open("/home/samariddin/Documents/cpp-course/huffman/test/testsec2");
//    // if(cheker(ans1, ans2)){
//    //     std::cout <<"YES\n";
//    // } else{
//    //     std::cout <<"NO\n";
//    // }
//    // ans1.close();
//    // ans2.close();
//    // huf text2;
//    // inFile1.open("/home/samariddin/Documents/cpp-course/huffman/test/testenc2");
//    // outFile1.open("/home/samariddin/Documents/cpp-course/huffman/test/testdec2");
//    // text2.encode(inFile1, outFile1);
//    // inFile1.close();
//    // outFile1.close();
//    // inFile2.open("/home/samariddin/Documents/cpp-course/huffman/test/testdec2");
//    // outFile2.open("/home/samariddin/Documents/cpp-course/huffman/test/testsec2");
//    // text.decode(inFile2, outFile2);
//    // inFile2.close();
//    // outFile2.close();
//    // ans1.open("/home/samariddin/Documents/cpp-course/huffman/test/testenc2");
//    // ans2.open("/home/samariddin/Documents/cpp-course/huffman/test/testsec2");
//    // if(cheker(ans1, ans2)){
//    //     std::cout <<"YES\n";
//    // } else{
//    //     std::cout <<"NO\n";
//    // }
//    // ans1.close();
//    // ans2.close();
//}

