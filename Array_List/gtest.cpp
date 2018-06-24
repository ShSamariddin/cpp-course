#include <gtest/gtest.h>
# include <bits/stdc++.h>
# include "array_list.h"

TEST(correctness, test2) {
    Array_List<int> a;
    for(int i = 0; i < 100; i ++){
    	a.push_back(i);
    }

    bool wr = true;
    for(int i = 0; i < 100; i ++){
    	std::cout <<i<<' '<<a.front()<<'\n';
    	if(a.front() != i){
    		wr = false;
    		break;
    	} 
    	a.pop_front();
    }
    EXPECT_TRUE(wr);
}
