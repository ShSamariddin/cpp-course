#include <iostream>
# include "array_list.h"

using namespace std;

int main()
{
    Array_List<int> buff;

        for (int i = 1; i <= 4; i++) {
        buff.push_back(i);
        }
        for(int i = 5; i <= 100; i++) {
        buff.push_front(i);
        //buff.erase(buff.end() - 2);
        }


//        Array_List<int>::iterator const  = buff.begin();



        buff.rbegin();
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


