#include <iostream>
# include "array_list.h"

using namespace std;

int main()
{
    Array_List<int> buff;

        for(int i = 0; i < 10; i ++){
            buff.push_back(i);
        }

        Array_List<int>::const_iterator it = buff.begin(), it1;
        it += 7;
        it = buff.insert(it, -7);
        cout << *it<<'\n';
        for(auto x : buff){
            cout <<x<<'\n';
        }
        //buff.rbegin();
        /*for(auto i:buff){
            cout<<i<<'\n';
        }
        swap(buff, buff);
        for(auto i:buff){
            cout<<i<<'\n';
        }

        buff.begin();

        buff.end();

        Array_List<int> const& buff_ref = buff;

        buff_ref.begin();*/
}


