all: main

main: 
	g++ -std=c++11 -fPIC -c huf.cpp huffman.cpp
	g++ -std=c++11 -c huffman_test.cpp
	g++ -std=c++11 huffman_test.o huf.o huffman.o -o huffman_test



