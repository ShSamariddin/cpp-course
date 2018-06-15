cmake_minimum_required(VERSION 2.8)

project(huffman)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14 -O0 -pedantic")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,undefined --coverage -D_GLIBCXX_DEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

add_library(huflib STATIC lib/constants.h
    lib/counter.h   lib/counter.cpp
    lib/tree.h      lib/tree.cpp
    lib/decoder.h   lib/decoder.cpp
    lib/encoder.h   lib/encoder.cpp
    lib/bitstring.h      lib/bitstring.cpp)

include_directories(lib)

add_executable(compression-util
    util/reader.h       util/reader.cpp
    util/writer.h       util/writer.cpp
    util/file_encoder.h util/file_encoder.cpp
    util/file_decoder.h util/file_decoder.cpp
    util/main.cpp)


target_link_libraries(compression-util huflib -lpthread)

set(TEST_FILES test/gtest/gtest_main.cc
        test/gtest/gtest-all.cc
        test/gtest/gtest.h
        test/huffman_test.cpp)

add_executable(tests ${TEST_FILES})

include_directories(test)

target_link_libraries(tests huflib -lpthread)


add_executable(my_test util/my_test.cpp)

target_link_libraries(my_test huflib)

