#include <iostream>
#include "./queue.cpp"

int main() {
    Queue<int>* queueA = new Queue<int>();
    Queue<int>* queueB = new Queue<int>(3);

    queueA->enqueue(1);
    queueA->enqueue(2);
    queueA->enqueue(3);
    queueA->enqueue(4);
    queueA->enqueue(3);
    queueA->enqueue(3);
    queueA->enqueue(3);
    queueA->enqueue(3);
    queueA->enqueue(3);
    queueA->enqueue(3);
    queueA->enqueue(3);



    queueB->enqueue(7);
    queueB->enqueue(8);
    queueB->enqueue(9);
    queueB->enqueue(5);

    queueA->dequeue();
    std::cout << "queue A: " << queueA->toString() << std::endl;
    std::cout << "queue B: " << queueB->toString() << std::endl;
    queueA->swap(queueB);
    std::cout << "queue A: " << queueA->toString() << std::endl;
    std::cout << "queue B: " << queueB->toString() << std::endl;

    std::cout << "Reverse queueA" << std::endl;
    std::cout << "queue A: " << queueA->reverse()->toString() << std::endl;
    delete queueA;
    delete queueB;
    return 0;
}