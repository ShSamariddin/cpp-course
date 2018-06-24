#include <gtest/gtest.h>
# include <bits/stdc++.h>
# include "array_list.h"

TEST(correctness, test1_easy) {
    Array_List<int> a;
    for(int i = 0; i < 100; i ++){
    	a.push_back(i);
    }

    bool wr = true;
    for(int i = 0; i < 100; i ++){
    	if(a.front() != i){
    		wr = false;
    		break;
    	} 
    	a.pop_front();
    }
    EXPECT_TRUE(wr);
}

TEST(correctness, test1_hard) {
    Array_List<int> a;
    for(int i = 0; i < 100000; i ++){
    	a.push_back(i);
    }

    bool wr = true;
    for(int i = 0; i < 100000; i ++){
    	if(a.front() != i){
    		wr = false;
    		break;
    	} 
    	a.pop_front();
    }
    EXPECT_TRUE(wr);
}

TEST(correctness, test2_easy) {
    Array_List<int> a;
    for(int i = 0; i < 100; i ++){
    	a.push_back(i);
    }

    bool wr = true;
    for(int i = 99; i >= 0; i --){
    	if(a.back() != i){
    		wr = false;
    		break;
    	} 
    	a.pop_back();
    }
    EXPECT_TRUE(wr);
}

TEST(correctness, test2_hard) {
    Array_List<int> a;
    for(int i = 0; i < 100000; i ++){
    	a.push_back(i);
    }

    bool wr = true;
    for(int i = 99999; i >= 0; i --){
    	if(a.back() != i){
    		wr = false;
    		break;
    	} 
    	a.pop_back();
    }
    EXPECT_TRUE(wr);
}

TEST(correctness, test3_easy) {
    Array_List<int> a;
    for(int i = 0; i < 100; i ++){
    	a.push_back(i);
    	a.push_front(i);
    }

    bool wr = true;
    for(int i = 99; i >= 0; i --){
    	if(a.back() != i){
    		wr = false;
    		break;
    	} 
    	a.pop_back();
    	if(a.front() != i){
    		wr = false;
    		break;
    	}
    	a.pop_front();
    }
    EXPECT_TRUE(wr);
}

TEST(correctness, test3_hard) {
    Array_List<int> a;
    for(int i = 0; i < 100000; i ++){
    	a.push_back(i);
    	a.push_front(i);
    }

    bool wr = true;
    for(int i = 99999; i >= 0; i --){
    	if(a.back() != i){
    		wr = false;
    		break;
    	} 
    	a.pop_back();
    	if(a.front() != i){
    		wr = false;
    		break;
    	}
    	a.pop_front();
    }
    EXPECT_TRUE(wr);
}

TEST(correctness, erase_easy) {
    Array_List<int> a;
    for(int i = 0; i < 100; i ++){
    	a.push_back(i);
    }

    bool wr = true;
    Array_List<int>::const_iterator it = a.begin();
    it += 50;
    for(int i = 50; i < 60; i ++){
    	a.erase(it);
    }
    for(int i = 0; i < 50; i ++){
    	if(a.front() != i){
    		wr = false;
    		break;
    	}
    	a.pop_front();
    }
    for(int i = 60; i < 100; i ++){
    	if(a.front() != i){
    		wr = false;
    		break;
    	}
    	a.pop_front();
    }
    EXPECT_TRUE(wr);
}

TEST(correctness, erase_hard) {
    Array_List<int> a;
    for(int i = 0; i < 10000; i ++){
    	a.push_back(i);
    }

    bool wr = true;
    Array_List<int>::const_iterator it = a.begin();
    it += 5000;
    for(int i = 5000; i < 6000; i ++){
    	a.erase(it);
    }
    for(int i = 0; i < 5000; i ++){
    	if(a.front() != i){
    		wr = false;
    		break;
    	}
    	a.pop_front();
    }
    for(int i = 6000; i < 10000; i ++){
    	if(a.front() != i){
    		wr = false;
    		break;
    	}
    	a.pop_front();
    }
    EXPECT_TRUE(wr);
}

TEST(correctness, insert_easy) {
    Array_List<int> a;
    bool wr = true;
    for(int i = 0; i < 10; i ++){
        a.push_back(i);
    }

    Array_List<int>::const_iterator it = a.begin();
    for(int i = 0; i < 10; i ++){
        it = a.begin();
        it++;
        a.insert(it, i);

    }
    EXPECT_TRUE(wr);
}
