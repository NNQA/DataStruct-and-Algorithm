#include <iostream>
#include <cstring>
#include "stack.h"
#include "node.cpp"

template <typename T> stack<T>::stack() {

    this->_top = nullptr;
    this->_size = 0;

}

template <typename T> stack<T>::stack(node<T> * top) {

    this->_top = top;
    this->_size = 1;
    for(node<T> *i = this->_top->getPrev(); i != nullptr; i = i->getPrev()) {
        ++this->_size;
    }

}

template <typename T> stack<T>::~stack() {

    node<T> * temp = new node<T>();
    for(node<T> *i = this->_top; i != nullptr; i = temp) {
        temp = i->getPrev();
        delete i;
    }

}

template<typename T> T stack<T>::top() const {

    if(this->_top == nullptr) {
        return T();
    }

    return this->_top->getValue();
}

template <typename T> stack<T>* stack<T>::setTop(node<T> * node) {

    if(this->_top != nullptr) {
        node->setPrev(this->_top);
    }
    this->_top = node;

    return this;

}

template<typename T> bool stack<T>::empty() const {
    return this->_top == nullptr;
}

template<typename T> std::size_t stack<T>::size() const {
    return this->_size;
}

template <typename T> stack<T>* stack<T>::push(T value) {

    node<T> * a = new node<T>(value);
    if(this->_top != nullptr) {
        a->setPrev(this->_top);
    }
    this->_top = a;
    ++this->_size;

    return this;
}

template <typename T> stack<T>* stack<T>::pop() {

    if(this->_top == nullptr) {
        throw std::runtime_error("pop an empty stack");
        return this;
    }  
    node<T> * temp = this->_top;
    this->_top = this->_top->getPrev();
    delete temp;
    --this->_size;

    return this;
}

template <typename T> stack<T>* stack<T>::swap(stack<T> * stack) {

    node<T> * temp = this->_top;
    this->_top = stack->_top;
    stack->_top = temp;

    return this;
}

template<typename T> std::string stack<T>::toString() const {

    std::string output = "";
    for(node<T>* i = this->_top; i != nullptr; i = i->getPrev()) {
        output += std::to_string(i->getValue()) + " ";
        
    }
    output += (this->empty() ? ("(empty)") : ("(size " + std::to_string(this->size()) + ")"));

    return output;
}

template <typename T> void _reverse(stack<T>* stack, node<T> * Node, node<T> * next) {

    if(Node->getPrev() != nullptr) {
        _reverse(stack, Node->getPrev(), Node);
    } else {
        stack->setTop(Node);
    }

    Node->setPrev(next);
}
template <typename T> stack<T>* stack<T>::reverse() {
    if (this->_top == nullptr) {
        return this;
    }
    _reverse<T>(this, this->_top, nullptr);

    return this;
}