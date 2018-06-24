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
        Array_List<int>::const_iterator it = a.begin();
        for(int i = 0; i < 10; i ++){
            it = a.begin();
            it += i * 2;
            a.insert(it, i);

        }
        cout<<'\n';
        for(auto i: a){
            cout << i<<' ';
        }
        cout<<'\n';



}

/*

*/
