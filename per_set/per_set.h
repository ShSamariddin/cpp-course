#ifndef PER_SET_H
#define PER_SET_H

# include<bits/stdc++.h>

class per_set
{
public:
    typedef int type;
    struct  node:std::enable_shared_from_this<node>
    {
        type  key;
        std::shared_ptr<node> left, right;
        node(int key);
        ~node();
        node(std::shared_ptr<node> const &other);
        node& operator=(const node& other);
        pair<per_set::node, bool> insert(type x);
    };
};

#endif // SET_H
