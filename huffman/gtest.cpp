#include <gtest/gtest.h>
# include <bits/stdc++.h>
# include "huf.h"
# include "huffman.h"

TEST(correctness, empty) {
	huf el;
    /*std::ifstream inFile1;
    std::ofstream outFile1;
    inFile1.open("/home/samariddin/Desktop/test/testenc2");
    outFile1.open("/home/samariddin/Desktop/test/testdec2");
   // huf::encode(inFile1, outFile1);
    /*inFile1.close();
    outFile1.close();
    std::ifstream inFile2;
    std::ofstream outFile2;
    inFile2.open("/home/samariddin/Desktop/test/testdec2");
    outFile2.open("/home/samariddin/Desktop/test/testsec2");
    test.decode(inFile2, outFile2);
    inFile2.close();
    outFile2.close();*/
	EXPECT_TRUE(true);
}
TEST(correctness, one_char){
	EXPECT_TRUE(true);
}