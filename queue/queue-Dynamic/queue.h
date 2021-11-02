#ifndef _QUEUE_H_INCLUDED_
#define _QUEUE_H_INCLUDED_

#include <cstring>

template <typename T> class Queue {
    private:
        std::size_t _capacity;
        std::size_t _rear;
        T * arr;
    public:
        Queue();
        Queue(std::size_t);
        ~Queue();
        T rear() const;
        bool empty() const;
        std::size_t size() const;
        std::size_t capacity() const;
        Queue* enqueue(T);
        Queue* dequeue();
        Queue* swap(Queue<T>*);
        std::string toString() const;
        Queue* reverse();

};
#endif