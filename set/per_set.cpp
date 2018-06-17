#include "per_set.h"


per_set::node::node(int key):key(key), left(nullptr), right(nullptr){}
per_set::node::node():ket(other->key), left(other->left), right(other->right){}
per_set::node::~node(){
    left.reset();
    right.reset();
}

