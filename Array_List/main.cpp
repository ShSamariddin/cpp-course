#include <iostream>
# include "array_list.h"

using namespace std;

int main()
{
    Array_List<int> a;
        for(int i = 0; i < 10; i ++){
            a.push_back(i);
        }

        bool wr = true;
        Array_List<int>::const_iterator it1 = a.begin();
        Array_List<int>::const_iterator it2 = a.begin();
        if(it1 == a.begin()){
            cout << "samar the best";
        }


}


