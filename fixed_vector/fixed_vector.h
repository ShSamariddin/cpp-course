//
// Created by Acer on 17.09.2018.
//

#ifndef UNTITLED3_FIXED_VEC_H
#define UNTITLED3_FIXED_VEC_H

# include <assert.h>
#include <iostream>

template<typename T, size_t si>
class fixed_vector {
public:
    using iterator = T *;
    using const_iterator = const T *;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    iterator begin() {
        return iterator(reinterpret_cast<T *>(data));
    }

    const_iterator begin() const {
        return const_iterator((reinterpret_cast<const T *>(data)));
    }

    iterator end() {
        return begin() + pos;
    }

    const_iterator end() const {
        return begin() + pos;
    }

    const_iterator cend() const {
        return end();
    }

    const_iterator cbegin() const {
        return begin();
    }

    reverse_iterator rbegin() {
        return reverse_iterator(end());
    }

    reverse_iterator rend() {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(end());
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(begin());
    }

    const_reverse_iterator crbegin() const {
        return const_reverse_iterator(end());
    }

    const_reverse_iterator crend() const {
        return const_reverse_iterator(begin());
    }

private:
public:
    fixed_vector() : pos(0) {}

    fixed_vector(const fixed_vector &other) : data(other.data), pos(other.pos) {}

    bool empty() const {//+
        return !pos;
    }

    size_t size() const {//+
        return pos;
    }

    constexpr size_t max_size() const {//+
        return si;
    }

    constexpr size_t capacity() const {//+
        return si;
    }

    void push_back(const T &value) {//+
        assert(pos < si);
        new(&data[pos])T(value);
        pos++;
    }

    void pop_back() {//+
        assert(pos != 0);
        reinterpret_cast<T *> (&data[pos - 1])->~T();
        pos--;
    }

    void clear() {//+
        while (pos) {
            pop_back();
        }
    }

    T &back() {//+
        return *reinterpret_cast<T *> (&data[pos - 1]);
    }

    const T &back() const {
        return *reinterpret_cast<const T *> (&data[pos - 1]);
    }

    T &front() {//+
        return *reinterpret_cast<T *> (&data[0]);
    }

    const T &front() const {
        return *reinterpret_cast<const T *> (&data[0]);
    }

    T &operator[](const size_t ind) {//+
        return *reinterpret_cast<T *> (&data[ind]);
    }

    const T &operator[](const size_t ind) const {
        return *reinterpret_cast<const T *>(&data[ind]);
    }

    iterator erase(const_iterator er_pos) {
        int i = std::distance(cbegin(), er_pos);
        for (; i + 1 < size(); i++) {
            data[i] = data[i + 1];
        }
        pop_back();
        return iterator(er_pos);
    }

    iterator insert(iterator in_pos, T const &value) {
        push_back(value);
        int x = std::distance(begin(), in_pos);
        for (int i = size() - 1; i >= x + 1; i--) {
            swap(data[i], data[i - 1]);
        }
        return in_pos;
    }

private:
    typename std::aligned_storage<sizeof(T), alignof(T)>::type data[si];
    size_t pos;

};

#endif //UNTITLED3_FIXED_VEC_H
