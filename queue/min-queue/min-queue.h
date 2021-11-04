#ifndef _MIN_QUEUE_H_INCLUDED_
#define _MIN_QUEUE_H_INCLUDED_
#include "../queue-Dynamic/queue.h"

template <typename T> class minQueue : public Queue<T> {
    private:
        Queue<T> * min_queue;
    public:
        minQueue();
        minQueue(std::size_t);
        ~minQueue();
        minQueue* enqueue(T);
        minQueue* dequeue();
        T min();
};

#endif