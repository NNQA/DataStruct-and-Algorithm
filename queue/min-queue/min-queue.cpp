#include "min-queue.h"
#include "./queue-Dynamic/queue.cpp"

template <typename T> minQueue<T>::minQueue() : Queue<T>::Queue() {
    this->min_queue = new Queue<T>();
}

template <typename T> minQueue<T>::minQueue(std::size_t capacity) : Queue<T>::Queue(capacity) {
    this->min_queue = new Queue<T>(capacity);
}

template <typename T> minQueue<T>::~minQueue() {
    delete this->min_queue;
}

template <typename T> minQueue<T>* minQueue<T>::enqueue(T value) {
    Queue<T>::enqueue(value);
    if(this->min_queue->empty()) {
        this->min_queue->enqueue(value);
    } else {
        while (this->min_queue->front() > value) {
            this->min_queue->dequeue();
        }
        this->min_queue->enqueue(value);
    }

    return this;
}
template <typename T> minQueue<T>* minQueue<T>::dequeue() {
    if(!this->empty()) {
        if(*(this->arr) == this->min_queue->front()) {
            this->min_queue->dequeue();
        }
    }
    Queue<T>::dequeue();

    return this;
}

template <typename T> T minQueue<T>::min() {
    if(this->min_queue->empty()) {
        return T();
    }

    return this->min_queue->front();
}