#include <iostream>
#include "stack.cpp"

int main() {
    stack<int>* stackA = new stack<int>();
    stack<int>* stackB = new stack<int>();

    stackA->push(1);
    stackA->push(2);
    stackA->push(3);
    stackA->push(4);
    stackA->push(5);

    stackA->reverse();
    std::cout << stackA->toString() << std::endl;
    delete stackA;
    delete stackB;
    return 0;
}