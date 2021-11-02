#ifndef _STACK_H_INCLUDED_
#define _STACK_H_INCLUDED_
#include "node.h"
#include <cstring>

template <typename T> class stack {
    private:
        node<T> * _top;
        std::size_t _size;
    public:
        stack();
        stack(node<T> *);
        ~stack();
        T top() const;
        stack<T>* setTop(node<T>*);
        bool empty() const;
        std::size_t size() const;
        stack* push(T);
        stack* pop();
        stack* swap(stack<T> *);
        std::string toString() const;
        stack* reverse();

};

#endif