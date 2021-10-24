#ifndef _node_included
#define _node_included
#include <iostream>



class Node {
    private:
        int value;
        Node *next;
    public:
            Node();
            Node(int);
            Node(int, Node*);
            Node* setValue(int);
            Node* setNext(Node*);
            Node* getNext();
            int getValue();
};

Node::Node() {
    this->value = 0;
    this->next = nullptr;
}

Node::Node(int value) {
    this->value = value;
    this->next = nullptr;
}

Node::Node(int value, Node* next) {
    this->value = value;
    this->next = next;
}

Node* Node::setValue(int value) {
    this->value = value;
    return this;
}

Node* Node::setNext(Node *node) {
    this->next = node;
    return this;
}

Node* Node::getNext() {
    return this->next;
}

int Node::getValue() {
    return this->value;
}    
#endif