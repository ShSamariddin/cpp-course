#ifndef SET_H
#define SET_H


class per_set
{
public:
    struct  node: std::enable_shared_from_this<node>
    {
        int  key;
        std::shared_ptr<node> left, right;
        node(int key);
        ~node();
        node(std::shared_ptr<node> const &other);
    };
};

#endif // SET_H
