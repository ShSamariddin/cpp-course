#ifndef FIXED_VECTOR
#define FIXED_VECTOR

# include<iostream>
# include<cmath>
# include<math.h>



template<typename T, size_t  s_si>

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
        friend class const_iterator;
        friend iterator operator+(iterator a, const int & b)  {
            return a+=b;
        }
        friend iterator operator-(iterator a, const int & b)  {
            return a-=b;
        }

        iterator(T* ar, int pos, const int &cap){
            this->ar = ar;
            this->pos = pos;
            this->cap = cap;
        }

        iterator():ar(nullptr), pos(0), cap(0){}

        iterator(const iterator& other): pos(other.pos), ar(other.ar), cap(other.cap){}

        ~iterator() = default;

        iterator& operator=(iterator const &other){
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

        bool operator==(const const_iterator &b) const{
            return (pos == b.pos && cap == b.cap && ar == b.ar);
        }

        bool operator!=(const const_iterator &b) const{
            return !(*this == b);
        }

        iterator& operator+= (const int rhs){
            pos += rhs;
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
            pos -= rhs;
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
            return *((T*)ar+pos);
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
        T* ar;
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
        const_iterator(T *ar, int pos, const int &cap) :ar(ar), pos(pos), cap(cap){}

        const_iterator(): ar(nullptr), pos(0), cap(0){}

        const_iterator(const const_iterator& other): pos(other.pos), ar(other.ar), cap(other.cap){}

        const_iterator(const iterator& other) : pos(other.pos), ar(other.ar), cap(other.cap){}

        ~const_iterator() = default;

        const_iterator& operator=(const_iterator other){
            pos = other.pos;
            ar = other.ar;
            cap = other.cap;
            return *this;
        }

        const_iterator& operator=(iterator other){
            pos = other.pos;
            ar = other.ar;
            cap = other.cap;
            return *this;
        }

        bool operator==(const const_iterator &b)const {
            return (pos == b.pos && cap == b.cap && ar == b.ar);
        }

        bool operator!=(const const_iterator &b)const {
            return !(*this == b);
        }
        bool operator==(const iterator &b)const {
            return (pos == b.pos && cap == b.cap && ar == b.ar);
        }

        bool operator!=(const iterator &b)const {
            return !(*this == b);
        }

        const_iterator& operator+= (const int rhs){
            pos += rhs;
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
            pos -= rhs;
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
            return *((T*)ar+pos);
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
        T* ar;
        int pos;
        int cap;
    };

    //friend Array_List;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;


    Array_List(): data(), ca_len(s_si){}
    Array_List(const Array_List& q):Array_List(){
        for(const_iterator it = q.begin(); it != q.end(); it ++){
            push_back(T(*it));
        }

    }
    ~Array_List(){
        for(const_iterator it = begin(); it != end(); it ++){
            (*it).~T();
        }
    }

  /*  Array_List& operator=(Array_List& other){
        Array_List<T, s_si> oth(other);
        swap(*this, oth);
        return *this;

    }*/

    // void swap(T& A,T&B)

    bool closer(int x){
        if(head > x){
            return (head - x <= (int) size() / 2);
        } else{
            return ((head + ca_len - x + 1 <= (int)size() / 2));
        }
    }
    iterator begin(){//+
        if(ca_len == 0){
            return iterator(const_cast<int *>(reinterpret_cast<const int*> (data + 0)), 0, 0);
        }
        return iterator(const_cast<int *>(reinterpret_cast<const int*> (data + 0)), 0, ca_len);
    }

    const_iterator begin() const {//+
        if(ca_len == 0){
            return iterator(const_cast<int *>(reinterpret_cast<const int*> (data + 0)), 0, 0);
        }
        return const_iterator(const_cast<int *>(reinterpret_cast<const int*> (data + 0)), 0 , ca_len);
    }

    reverse_iterator rbegin(){//+
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const{//+
        return const_reverse_iterator(end());
    }

    iterator end(){//+
        if(ca_len == 0){
            return iterator(const_cast<int *>(reinterpret_cast<const int*> (data + 0)), 0, 0);
        }
        return iterator(const_cast<int *>(reinterpret_cast<const int*> (data + 0)),head - 1, ca_len);
    }

    const_iterator end() const {//+
        if(ca_len == 0){
            return iterator(const_cast<int *>(reinterpret_cast<const int*> (data + 0)), 0, 0);
        }
        return const_iterator(const_cast<int *>(reinterpret_cast<const int*> (data + 0)), head - 1, ca_len);
    }

    reverse_iterator rend(){//+
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const{//+
        return const_reverse_iterator(begin());
    }

    bool empty(){//+
        return (size() == 0);
    }

    iterator insert(const_iterator no, T const& value){
        if(len >= ca_len) {
            throw std::runtime_error("my_error1");
        }
        len++;
        int pos_i = no.position();
        for(int i = head; i > pos_i; i --){
            new(data+i)T(*reinterpret_cast<const T*>(data + i - 1));
        }
        head++;
        new(data+pos_i)T(value);
        return iterator(const_cast<int *>(reinterpret_cast<const int*> (data + 0)), pos_i, ca_len);
    }

    iterator erase(const_iterator no){
        int pos_i = no.position();
        len--;
        for(int i = pos_i; i < head; i ++){
            new(data+i)T(*reinterpret_cast<const T*>(data + i + 1));
        }
        head--;
        return iterator(const_cast<int *>(reinterpret_cast<const int*> (data + 0)), pos_i, ca_len);
    }

    void push_back(T value){//+
        if(len >= ca_len) {
            throw std::runtime_error("my_error1");
        }
        new(data + head)T(value);
        len++;
        head++;
    }

    void pop_back(){
        if(len == 0){
            throw std::runtime_error("my_error1");
        } else{
            len--;
            reinterpret_cast<const T*>(data+head)->~T();
            head--;
        }
    }


    T& operator[](size_t ind){//+
        return *((T*)data + ind);
        //return a[t];
    }

    T& operator[](size_t ind) const{//+
        return *((T*)data+ind);
        //return a[t];
    }

    T& back(){//+
        return *((T*)data+head - 1);
        //return a[tail];
    }


    T& front(){//+
        return *((T*)data+0);
        //return a[(head + ca_len - 1) % ca_len];
    }

    T& back() const{//+
        return *((T*)data+head - 1);
        //return a[tail];
    }

    T& front() const{//+
        return *((T*)data + 0);
        //return data[(head + ca_len - 1) % ca_len];
    }

    size_t max_size() const{
        return ca_len;
    }

    size_t capcity() const{
        return ca_len;
    }

    size_t size() const{//+
        return len;
    }

    /*template<typename S, size_t  ss_si>
    friend void swap(Array_List<S, ss_si>& first, Array_List<S, ss_si>& second);*/

private:
    typename std::aligned_storage<sizeof(T), alignof(T)>::type data[s_si];
    size_t ca_len = 0, len = 0, head = 0;
};

/*template <typename T>
typename Array_List<T>::iterator operator+(typename Array_List<T>::iterator a, const int & b) {
    return a+=b;
}*/

/*template <typename T>
typename Array_List<T>::iterator operator-(typename Array_List<T>::iterator a, const int & b) {
    return a-=b;
}*/

/*template <typename T>
void swap(Array_List<T>& first, Array_List<T>& second){
    std::swap(second.a, first.a);
    std::swap(second.ca_len, first.ca_len);
    std::swap(first.head, second.head);
    std::swap(first.tail, second.tail);
}
*/
#endif // ARRAY_LIST_H
