//
// Created by Samariddin on 13.10.2018.
//

#ifndef UNTITLED_OPTIONAL_H
#define UNTITLED_OPTIONAL_H

# include <iostream>

template<typename T>
struct Optional {
    Optional() : is_value(false) {}

    Optional(T const &value) {
        new(&this->value)T(value);
        this->is_value = true;
    }

    Optional(Optional<T> const &rhs) {
        if (!rhs.is_value) {
            this->is_value = false;
        } else {
            new (&value) T((*reinterpret_cast<T const*>(&rhs.value)));
            this->is_value = rhs.is_value;
        }
    }

    Optional<T> &operator=(Optional const &rhs) {
        Optional<T> new_x(rhs);
        swap(*this, new_x);
        return *this;
    }

    ~Optional() {
        if (is_value) {
            reinterpret_cast<T*> (&value)->~T();
        }
    }

    void clear() {
        if (is_value) {
            reinterpret_cast<T*> (&value)->~T();
            is_value = false;
        }
    }

    explicit operator bool() const {
        return is_value;
    }

    /*T* get_value(){
        return x;
    };*/
    T &operator*() {
        if(!is_value){
            throw std::runtime_error("Dereferencing of empty optional");
        }
        return *reinterpret_cast<T *> (&value);
    }

    T *operator->() {
        return reinterpret_cast<T *> (&value);
    }

    template<typename S>
    friend void swap(Optional<S> &one, Optional<S> &two);

private:
    typename std::aligned_storage<sizeof(T), alignof(T)>::type value;
    bool is_value;
};

template<typename T>
void swap(Optional<T> &one, Optional<T> &two) {
//    T t1 = (*reinterpret_cast<T *>(&one.value));
//    T t2 = (*reinterpret_cast<T *>(&two.value));
//    new (&one.value) T((*reinterpret_cast<T *>(&two.value)));
//    new (&two.value) T((*reinterpret_cast<T *>(&t.value)));
    if(one.is_value && two.is_value) {
        std::swap((*reinterpret_cast<T *>(&one.value)), *reinterpret_cast<T *>(&two.value));
    } else{
       if(one.is_value){
           new(&two.value) T(*reinterpret_cast<T *>(&one.value));
           reinterpret_cast<T*> (&one.value)->~T();
       } else if(two.is_value){
           new(&one.value) T(*reinterpret_cast<T *>(&two.value));
           reinterpret_cast<T*> (&two.value)->~T();
       }
    }
    std::swap(one.is_value, two.is_value);
    //swap(one.is_value, two.is_value);
//    one.is_value = two.is_value;
//    one.is_value = two.is_value;
//    two.is_value = t.is_value;
}

#endif //UNTITLED_OPTIONAL_H
