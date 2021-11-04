#include <iostream>
#include "./min-queue.cpp"

int main() {
    minQueue<int> * queue = new minQueue<int>();
    std::cout << queue->enqueue(2)->toString() << "; min = " << queue->min() << std::endl;
    std::cout << queue->enqueue(3)->toString() << "; min = " << queue->min() << std::endl;
    std::cout << queue->enqueue(5)->toString() << "; min = " << queue->min() << std::endl;
    std::cout << queue->enqueue(1)->toString() << "; min = " << queue->min() << std::endl;
    std::cout << queue->enqueue(6)->toString() << "; min = " << queue->min() << std::endl;
    std::cout << queue->enqueue(7)->toString() << "; min = " << queue->min() << std::endl;

    while(!queue->empty()) {
        std::cout << queue->dequeue()->toString() << "; min = " << queue->min() << std::endl;
    }
    delete queue;
    std::cout << "ok";
    return 0;
}