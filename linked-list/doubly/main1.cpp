#include <iostream>
#include "list.h"

int main() {
    List *list = new List();
    Node *a = new Node(1);
    Node *b = new Node(5);
    Node *c = new Node(10);
    Node *d = new Node(20);
    Node *e = new Node(50);
    list->pushBack(a)->pushBack(b)->pushBack(c)->pushBack(d)->pushBack(e);
    list->printAll();
    return 0;
}