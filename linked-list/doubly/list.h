#ifndef _list_included
#define _list_included
#include "node.h"
#include <iostream>
#include <math.h>

class List {
    private:
        Node *head;
        Node *tail;
    public:
        List();
        List(Node*);
        List(Node*, Node*);
        int size();
        List * pushBack(Node * node);
        List * pushFront(Node * node);
        List * printAll();
};

List::List() {
    this->head = nullptr;
    this->tail = nullptr;
}
List::List(Node * node) {
    this->head = node;
    this->tail = nullptr;
}
List::List(Node * head, Node * tail) {
    this->head = head;
    this->tail = tail;
}
int List::size() {
    int count = 0; 
    for(Node * i = this->head; i != nullptr; i = i->getNext()) {
        count++;
    }
    return count;
}
List* List::pushBack(Node * node) {
    if(this->head == nullptr) {
        this->pushFront(node);
        return this;
    }   
    if(this->tail == nullptr) {
        this->head->setNext(node);
        this->head->setPrev(this->head);
        this->tail = node;
    }
    else {
        this->tail->setNext(node);
        node->setPrev(this->tail);
        this->tail = node;
    }
    return this;
}
List* List::pushFront(Node * node) {
    if(this->head != nullptr) {
        node->setNext(this->head);
        this->head->setPrev(node);
    }
    this->head = node;
    return this;
}
List* List::printAll() {
    bool first = true;
    for(Node *i = this->tail; i != nullptr; i = i->getPrev()) {
        if(!first) {
            std::cout << " ";
        } else {
            first = false;
        }
        std::cout << i->getValue();
    }
    std::cout << std::ends;
    return this;
}

#endif