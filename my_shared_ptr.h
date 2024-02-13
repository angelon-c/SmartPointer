//
// Created by angel on 2/12/24.
//
#include <iostream>

using namespace std;
#ifndef EJEMPLOPUNTEROS_MY_SHARED_PTR_H
#define EJEMPLOPUNTEROS_MY_SHARED_PTR_H

typedef unsigned int uint;

template<class T>
class my_shared_ptr {
private:
    T *ptr = nullptr;
    uint *refcount = nullptr;
public:
    my_shared_ptr() :
            ptr(nullptr), refcount(new uint(0)) {

    }

    my_shared_ptr(T *ptr) : ptr(ptr), refcount(new uint(1)) {

    }

    my_shared_ptr(const my_shared_ptr &obj) {
        this->ptr = obj.ptr;
        this->refcount = obj.refcount;
        if(nullptr != obj.ptr)
        {
            (*this->refcount)++;
        }
    }

    my_shared_ptr& operator=(const my_shared_ptr & obj)
    {
        cleanup();
        this->ptr = obj.ptr;
        this-> refcount = obj.refcount;
        if(nullptr != obj.ptr)
        {
            (*this->refcount)++;
        }
    }


    uint get_count() const {
        return *refcount;
    }

    T *get() const {
        return this->ptr;
    }

    T *operator->() const {
        return this->ptr;
    }

    T &operator*() const {
        return this->ptr;
    }

    ~my_shared_ptr() {
        cleanup();
        cout << "Eliminado" << endl;
    }

public:
    void cleanup() {
        if (*refcount == 0) {
            if (nullptr != ptr) {
                delete ptr;
                delete refcount;
            }
        } else {
            (*refcount)--;
        }
    }

};


#endif //EJEMPLOPUNTEROS_MY_SHARED_PTR_H
