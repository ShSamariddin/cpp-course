#include <iostream>
# include "array_list.h"

using namespace std;

int main()
{
    Array_List<int> a;
    for(int i = 0; i < 20; i ++)  {
        a.push_back(i);
    }
    for(auto it: a){
        cout <<it<<' ';
    }
    cout<<'\n';
    Array_List<int>::const_iterator it = a.begin();

    a.erase(it);
    for(auto it: a){
        cout <<it<<' ';
    }
    cout<<'\n';
}

/*

*/
