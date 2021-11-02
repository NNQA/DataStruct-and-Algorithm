
#include "node.h"


template <typename T> node<T>::node() {
    this->value = 0;
    this->prev = nullptr;
}
template <typename T> node<T>::node(T value) {
    this->value = value;
    this->prev = nullptr;
}
template <typename T> node<T>::node(T value, node * prev) {
    this->value = value;
    this->prev = prev;
}
template <typename T> node<T>* node<T>::setPrev(node * prev) {
    this->prev = prev;
    return this;
}
template <typename T> node<T>* node<T>::setValue(T value) {
    this->value = value;
    return this;
}
template <typename T> node<T>* node<T>::getPrev() const {
    return this->prev;
}
template <typename T> T node<T>::getValue() const {
    return this->value;
}