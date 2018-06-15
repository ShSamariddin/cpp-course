all: main

main: 
	g++ -std=c++11 -fPIC -c huf.cpp huffman.cpp
	g++ -std=c++11 -c huffman_test.cpp
	g++ -std=c++11 huffman_test.o huf.o huffman.o -o huffman_test
	g++ -std=c++11 -I/home/samariddin/Documents/cpp-course/huffman gtest/gtest_main.cc gtest/gtest-all.cc gtest.cpp huf.cpp huffman.cpp -o gt -lgmp -lgmpxx -lpthread



