#include "per_set.h"


per_set::node::node(type key):key(key), left(nullptr), right(nullptr){}
per_set::node::~node(){
    left.reset();
    right.reset();
}

per_set::node& per_set::node::operator=(const per_set::node& rhs) {
    key = rhs.key;
    left = rhs.left;
    right = rhs.right;
}
per_set::node::node(std::shared_ptr<node> const &other) : key(other->key), left(other->left), right(other->right) {}

std::pair<pair<std::shared_ptr<node>, bool>  paer_set::node::insert(type x){

    if(key == x){
        return shared_from_this();
    } else if(x < key){
        if(left){
            return left->insert(x);
        } else{
            std::shared_ptr<node>
        }
    }
}
