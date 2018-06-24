#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

# include<iostream>
# include<cmath>
# include<math.h>



template<typename T>

class Array_List
{
public:
    struct const_iterator;

    struct iterator
    {
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T &;
        using iterator_category = std::random_access_iterator_tag;
        friend iterator operator+(iterator a, const int & b)  {
            return a+=b;
        }
        friend iterator operator-(iterator a, const int & b)  {
            return a-=b;
        }

        friend const_iterator;
        iterator(T *ar, int pos, const int &cap){
            this->ar = ar;
            this->pos = pos;
            this->cap = cap;
        }

        iterator(){}

        iterator(const iterator& other){
            pos = other.pos;
            ar = other.ar;
            cap = other.cap;
        }

        ~iterator(){}

        iterator operator=(iterator other){
            pos = other.pos;
            ar = other.ar;
            cap = other.cap;
            return *this;
        }

        bool operator==(const iterator &b) const{
            return (pos == b.pos && cap == b.cap && ar == b.ar);
        }

        bool operator!=(const iterator &b) const{
            return !(*this == b);
        }

        iterator& operator+= (const int rhs){
            pos -= rhs;
            pos += cap;
            pos %= cap;
            return *this;
        }


        iterator operator++ (int){

            iterator it = *this;
            ++*this;
            return it;
        }

        iterator& operator++ (){
            return *this += 1;
        }

        iterator& operator-= (const int rhs){
            pos += rhs;
            pos %= cap;
            return *this;
        }


//        int operator-(iterator a, iterator b){
//            return a.pos - b.pos;
//        }

        iterator operator--(int){
            iterator it = *this;
            --*this;
            return it;
        }

        iterator& operator--(){
            return *this -= 1;
        }

        T& operator*(){
            return ar[pos];
        }

        bool operator> (iterator a){
            return (pos > a.pos);
        }

        bool operator< (iterator a){
            return (pos < a.pos);
        }

        bool operator>= (iterator a){
            return (pos >= a.pos);
        }

        bool operator<= (iterator a){
            return (pos <= a.pos);
        }

        int position(){
            return pos;
        }

    private:
        int* ar;
        int pos, cap;
    };

    struct const_iterator
    {
        using difference_type = std::ptrdiff_t;
        using value_type = const T;
        using pointer = const T *;
        using reference = const T &;
        using iterator_category =const  std::random_access_iterator_tag;
        friend iterator;
        const_iterator(T *ar, int pos, const int &cap){
            this->ar = ar;
            this->pos = pos;
            this->cap = cap;
        }

        const_iterator(){}

        const_iterator(const const_iterator& other){
            pos = other.pos;
            ar = other.ar;
            cap = other.cap;
        }

        const_iterator(const iterator& other){
            pos = other.pos;
            ar = other.ar;
            cap = other.cap;
        }

        ~const_iterator(){}

        const_iterator operator=(const_iterator other){
            pos = other.pos;
            ar = other.ar;
            cap = other.cap;
            return *this;
        }

        const_iterator operator=(iterator other){
            pos = other.pos;
            ar = other.ar;
            cap = other.cap;
            return *this;
        }

        bool operator==(const const_iterator &b){
            return (pos == b.pos && cap == b.cap && ar == b.ar);
        }

        bool operator!=(const const_iterator &b){
            return !(*this == b);
        }

        const_iterator& operator+= (const int rhs){
            pos -= rhs;
            pos += cap;
            pos %= cap;
            return *this;
        }

        const_iterator operator++ (int){

            const_iterator it = *this;
            ++*this;
            return it;
        }

        const_iterator& operator++ (){
            return *this += 1;
        }

        const_iterator& operator-= (const int rhs){
            pos += rhs;
            pos %= cap;
            return *this;
        }

        const_iterator operator--(int){
            const_iterator it = *this;
            --*this;
            return it;
        }


        const_iterator& operator--(){
            return *this -= 1;
        }

        const T& operator*(){
            return ar[pos];
        }

        bool operator> (const_iterator a){
            return (pos > a.pos);
        }

        bool operator< (const_iterator a){
            return (pos < a.pos);
        }

        bool operator>= (const_iterator a){
            return (pos >= a.pos);
        }

        bool operator<= (const_iterator a){
            return (pos <= a.pos);
        }


        int position() const{
            return pos;
        }




    private:
        int* ar;
        int pos;
        size_t cap;
    };

    //friend Array_List;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;


    Array_List(){
        a = static_cast<T*>(operator new[](sizeof(T) * 10));
        ca_len = 10, len = 0;
        head = tail = 0;
    }
    ~Array_List(){
        delete[] a;
    }

    // void swap(T& A,T&B)

    bool closer(int x){
        if(head > x){
            if(head - x <= size() / 2){
                return true;
            } else{
                return false;
            }
        } else{
            if(head + ca_len - x + 1 <= size() / 2){
                return true;
            } else{
                return false;
            }
        }
    }

    const_iterator insert(const_iterator no, T const& value){
        int x = no.position();
        int kol;
        if(x > head){
            kol = ca_len - x + head ;
        } else{
            kol = head - x;
        }
        if(closer(x)){
            push_front(value);
            x = (head - kol + ca_len  - 1) % ca_len;
            int t = head - 1;

            while(x != (t - 1 + ca_len) % ca_len){
                std::swap(a[t], a[(t - 1 + ca_len) % ca_len]);
                t--;
                t %= ca_len;
            }
            return const_iterator(a, t, ca_len);
        } else{
            push_back(value);
            x = (head - kol + ca_len) % ca_len;
            int t = tail;
            while(x != (t + 1) % ca_len){
                std::swap(a[t], a[(t + 1) % ca_len]);
                t++;
                t %= ca_len;
            }
            return const_iterator(a, t, ca_len);
        }
    }

    const_iterator erase(const_iterator no){
        int x = no.position();
        if(closer(x)){
            int t = x;
            while(head != (t + 1) % ca_len){
                std::swap(a[t], a[(t + 1) % ca_len]);
                t ++;
                t %= ca_len;
            }
            pop_front();
            return const_iterator(a, (x - 1 + ca_len) % ca_len, ca_len);
        } else{
            int t = x;
            while(tail != t){
                std::swap(a[t], a[(t - 1 + ca_len) % ca_len]);
                t--;
                t += ca_len;
                t %= ca_len;
            }
            pop_back();
            return const_iterator(a, x, ca_len);

        }

    }
    iterator begin(){
        return iterator(a, (head - 1 + ca_len) % ca_len, ca_len);
    }

    const_iterator begin() const {
        return const_iterator(a, (head - 1 + ca_len)% ca_len, ca_len);
    }

    reverse_iterator rbegin(){
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const{
        return const_reverse_iterator(end());
    }

    iterator end(){
        return iterator(a,(tail - 1 + ca_len) % ca_len, ca_len);
    }

    const_iterator end() const {
        return const_iterator(a, (tail - 1 + ca_len) % ca_len, ca_len);
    }

    reverse_iterator rend(){
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const{
        return const_reverse_iterator(begin());
    }

    bool empty(){
        if(size() == 0){
            return true;
        } else{
            return false;
        }
    }

    void clear(){
        delete[] a;
        a = static_cast<T*>(operator new[](sizeof(T) * 10));
        ca_len = 10;len = 0;
        head = tail = 0;
    }

    void copy(){
        T* new_a = static_cast<T*>(operator new[](sizeof(T) * ca_len * 2));
        int new_head = 0;
        try{
            if(head >= tail){
                for(int i = tail; i < head; i --){
                    new (&new_a[new_head]) T (a[i]);
                    new_head++;
                }
            } else{
                for(int i = tail; i < ca_len; i ++){
                    new (&new_a[new_head]) T (a[i]);
                    new_head++;
                }
                for(int i = 0; i < head; i ++){
                    new (&new_a[new_head]) T (a[i]);
                    new_head++;
                }
            }
        } catch (std::runtime_error &e){
            delete new_a;
        }

        ca_len *= 2;
        delete[] a;
        a = new_a;
        head = new_head;
        tail = 0;
    }
    void minu(size_t &x){
        if(x == 0){
            x = ca_len - 1;
        } else{
            x --;
        }
    }

    void plus(size_t &x){
        x++;
        if(x == ca_len){
            x = 0;
        }
    }

    void push_back(T value){
        len++;
        if(len == ca_len - 2){
            copy();

        }
        minu(tail);
        a[tail] = value;
    }

    void push_front(T value){
        len++;
        if(len == ca_len - 2){
            copy();
        }
        a[head] = value;
        plus(head);
    }


    void pop_back(){
        if(len == 0){
            throw std::runtime_error("my_error1");
        } else{
            len--;
            plus(tail);
        }
    }

    void pop_front(){
        if(len == 0){
            throw std::runtime_error("my_error2");
        } else{
            len--;
            minu(head);
        }
    }

    T& operator[](size_t ind){
        int t = head;
        t -= ind;
        t += ca_len;
        t %= ca_len;
        return a[t];
    }

    T& operator[](size_t ind) const{
        int t = head;
        t -= ind;
        t += ca_len;
        t %= ca_len;
        return a[t];
    }

    T& back(){
        return a[tail];
    }

    T& front(){
        return a[(head + ca_len - 1) % ca_len];
    }

    T& back() const{
        return a[tail];
    }

    T& front() const{
        return a[(head + ca_len - 1) % ca_len];
    }

    size_t size(){
        return len;
    }
    template<typename S>
   friend void swap(Array_List<S>& first, Array_List<S>& second);

private:
    T* a;
    size_t ca_len = 100, len = 0, head = 0, tail = 0;

};

/*template <typename T>
typename Array_List<T>::iterator operator+(typename Array_List<T>::iterator a, const int & b) {
    return a+=b;
}*/

/*template <typename T>
typename Array_List<T>::iterator operator-(typename Array_List<T>::iterator a, const int & b) {
    return a-=b;
}*/

template <typename T>
void swap(Array_List<T>& first, Array_List<T>& second){
    std::swap(second.a, first.a);
    std::swap(second.ca_len, first.ca_len);
    std::swap(first.head, second.head);
    std::swap(first.tail, second.tail);
}

#endif // ARRAY_LIST_H
