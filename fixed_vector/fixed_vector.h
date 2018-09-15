#ifndef UN3_FIXED_VECTOR
#define UN3_FIXED_VECTOR

# include<iostream>
# include<cmath>
# include<math.h>


template<typename T, size_t s_si>

class Array_List {
public:
    struct const_iterator;

    struct iterator {
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T &;
        using iterator_category = std::random_access_iterator_tag;

        friend class const_iterator;

        friend iterator operator+(iterator a, const size_t &b) {
            return a += b;
        }

        friend iterator operator-(iterator a, const size_t &b) {
            return a -= b;
        }

        iterator(T *ar, int pos, int cap) : ar(ar), pos(pos), cap(cap) {}

        iterator() : ar(nullptr), pos(0), cap(0) {}

        iterator(const iterator &other) : pos(other.pos), ar(other.ar), cap(other.cap) {}

        ~iterator() = default;

        iterator &operator=(iterator const &other) {
            //ispravit
            pos = other.pos;
            ar = other.ar;
            cap = other.cap;
            return *this;
        }

        bool operator==(const iterator &b) const {
            return (pos == b.pos && cap == b.cap && ar == b.ar);
        }

        bool operator!=(const iterator &b) const {
            return !(*this == b);
        }

        bool operator==(const const_iterator &b) const {
            return (pos == b.pos && cap == b.cap && ar == b.ar);
        }

        bool operator!=(const const_iterator &b) const {
            return !(*this == b);
        }

        iterator &operator+=(int rhs) {
            // pos > cap
            if (pos + rhs >= cap || pos + rhs < 0) {
                throw "Error";
            }
            pos += rhs;

            return *this;
        }


        const iterator operator++(int) {

            iterator it = *this;
            ++*this;
            return it;
        }

        iterator &operator++() {
            return *this += 1;
        }

        iterator &operator-=(const int rhs) {
            if (pos - rhs < 0 || pos - rhs >= cap) {
                throw "Error";
            }
            pos -= rhs;
            return *this;
        }


        friend int operator-(iterator a, iterator b) {
            return a.pos - b.pos;
        }

        friend int operator+(iterator a, iterator b) {
            return a.pos + b.pos;
        }

        const iterator operator--(int) {
            iterator it = *this;
            --*this;
            return it;
        }

        iterator &operator--() {
            return *this -= 1;
        }

        T &operator*() {
            return *((T *) ar + pos);
        }

        bool operator>(const iterator &a) {// hal kn
            return (pos > a.pos);
        }

        bool operator<(iterator a) {
            return (pos < a.pos);
        }

        bool operator>=(iterator a) {
            return (pos >= a.pos);
        }

        bool operator<=(iterator a) {
            return (pos <= a.pos);
        }

    private:
        T *ar;
        int pos, cap;
    };


    struct const_iterator {
        using difference_type = std::ptrdiff_t;
        using value_type = const T;
        using pointer = const T *;
        using reference = const T &;
        using iterator_category =const std::random_access_iterator_tag;
        friend iterator;

        const_iterator(T *ar, int pos, const int &cap) : ar(ar), pos(pos), cap(cap) {}

        const_iterator() : ar(nullptr), pos(0), cap(0) {}

        const_iterator(const const_iterator &other) : pos(other.pos), ar(other.ar), cap(other.cap) {}

        const_iterator(const iterator &other) : pos(other.pos), ar(other.ar), cap(other.cap) {}

        ~const_iterator() = default;

        const_iterator &operator=(const_iterator other) {
            pos = other.pos;
            ar = other.ar;
            cap = other.cap;
            return *this;
        }

        const_iterator &operator=(iterator other) {
            pos = other.pos;
            ar = other.ar;
            cap = other.cap;
            return *this;
        }

        bool operator==(const const_iterator &b) const {
            return (pos == b.pos && cap == b.cap && ar == b.ar);
        }

        bool operator!=(const const_iterator &b) const {
            return !(*this == b);
        }

        bool operator==(const iterator &b) const {
            return (pos == b.pos && cap == b.cap && ar == b.ar);
        }

        bool operator!=(const iterator &b) const {
            return !(*this == b);
        }

        const_iterator &operator+=(const int rhs) {
            if (pos + rhs >= cap && pos + rhs < 0) {
                throw "My Error";
            }
            pos += rhs;
            return *this;
        }

        const const_iterator operator++(int) {

            const_iterator it = *this;
            ++*this;
            return it;
        }

        const_iterator &operator++() {
            return *this += 1;
        }

        const_iterator &operator-=(const int rhs) {
            if (pos - rhs < 0 || pos - rhs >= cap) {
                throw "my error";
            }
            pos -= rhs;
            return *this;
        }

        const const_iterator operator--(int) {
            const_iterator it = *this;
            --*this;
            return it;
        }


        const_iterator &operator--() {
            return *this -= 1;
        }

        const T &operator*() {
            return *((T *) ar + pos);
        }

        bool operator>(const_iterator a) {
            return (pos > a.pos);
        }

        bool operator<(const_iterator a) {
            return (pos < a.pos);
        }

        bool operator>=(const_iterator a) {
            return (pos >= a.pos);
        }

        bool operator<=(const_iterator a) {
            return (pos <= a.pos);
        }

        int position() const {
            return pos;
        }

        friend class Array_List;


    private:
        T *ar;
        int pos;
        int cap;
    };

    //friend Array_List;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;


    Array_List() : data(), ca_len(s_si + 4) {}

    Array_List(const Array_List &q) : Array_List() {
        try {
            for (const_iterator it = q.begin(); it != q.end(); it++) {
                //std::cout <<"sa"<<*it<<"sa\n";
                push_back(T(*it));
            }
        } catch (...) {
            while (!empty()) {
                pop_back();
            }
        }

    }

    ~Array_List() {
        for (const_iterator it = begin(); it != end(); it++) {
            (*it).~T();
        }
    }

    Array_List &operator=(Array_List const &other) {
        std::cout << "samar";
        Array_List<T, s_si> oth(other);
        swap(*this, oth);
        return *this;

    }


    iterator begin() {//+
        return iterator(reinterpret_cast<T *>(data), 0, len);
    }

    const_iterator begin() const {//+
        return iterator(reinterpret_cast<T *>(data + 0), 0, len);
    }

    reverse_iterator rbegin() {//+
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const {//+
        return const_reverse_iterator(end());
    }

    iterator end() {//+
        return iterator(reinterpret_cast<T *>(data), len, len);
    }

    const_iterator end() const {//+
        return iterator(reinterpret_cast<T *>(data), len, len);
    }

    reverse_iterator rend() {//+
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const {//+
        return const_reverse_iterator(begin());
    }

    bool empty() {//+
        return (size() == 0);
    }

    void clear() {
        while (!empty()) {
            pop_back();
        }
    }

    iterator insert(const_iterator no, T const &value) {
        if (len >= ca_len) {
            throw std::runtime_error("my_error1");
        }
        int pos_i = no.pos;
        for (int i = len; i > pos_i; i--) {
            new(data + i) T(*reinterpret_cast<T*>(data + i - 1));
        }
        len++;
        new(data + pos_i) T(value);
        return iterator(reinterpret_cast<T *> (data + 0), pos_i, ca_len);
    }

    iterator erase(const_iterator no) {
        int pos_i = no.position();
        len--;
        // redo
        for (int i = pos_i; i < len; i++) {
            // make delete
            //new(data+i)T(*reinterpret_cast<const T*>(data + i + 1));
            new(data + i)T((*this)[i + 1]);
        }
        return iterator(const_cast<T *>(reinterpret_cast<const T *> (data + 0)), pos_i, ca_len);
    }

    void push_back(const T &value) {//+
        if (len >= ca_len) {
            throw std::runtime_error("my_error1");
        }
        new(data + len) T(value);
        len++;
    }

    void pop_back() {
        if (len == 0) {
            throw std::runtime_error("my_error1");
        } else {
            reinterpret_cast<T *>(data + len - 1)->~T();
            len--;
        }
    }


    T &operator[](size_t ind) {//+
        return *((T *) data + ind);
    }

    const T &operator[](size_t ind) const {//+
        return *((T *) data + ind);
    }

    T &back() {//+
        return *((T *) data + len - 1);
    }


    T &front() {//+
        return *((T *) data + 0);
    }

    const T &back() const {//+
        return *((T *) data + len - 1);
    }

    const T &front() const {//+
        return *((T *) data + 0);
    }

    const size_t max_size() const {
        return ca_len - 4;
    }

    const size_t capacity() const {
        return ca_len - 4;
    }

    const size_t size() const {//+
        return len;
    }

    template<typename S, size_t ss_si>
    friend void swap(Array_List<S, ss_si> &first, Array_List<S, ss_si> &second);

private:
    typename std::aligned_storage<sizeof(T), alignof(T)>::type data[s_si];
    size_t ca_len = 0, len = 0;
};

template<typename T, size_t ss_s>
typename Array_List<T, ss_s>::iterator operator+(typename Array_List<T, ss_s>::iterator a, const int &b) {
    return a += b;
}

template<typename T, size_t ss_s>
typename Array_List<T, ss_s>::iterator operator-(typename Array_List<T, ss_s>::iterator a, const int &b) {
    return a -= b;
}

template<typename T, size_t ss_s>
void swap(Array_List<T, ss_s> &first, Array_List<T, ss_s> &second) {
    std::swap(second.data, first.data);
    std::swap(second.ca_len, first.ca_len);
    std::swap(first.len, second.len);
}

#endif // ARRAY_LIST_H
