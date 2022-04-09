// template for Queue ADT (abstract queue class)

#ifndef QUEUE_H
#define QUEUE_H

template <typename E>

class Queue
{
    public:
        Queue() {} // default constructor
        ~Queue() {} // base destructor

        // reinitializes the queue
        virtual void clear() = 0;

        // place element at the end of the queue
        // @param item: element being enqueued
        virtual void enqueue(const E& item) = 0;

        // remove and return the element at the front of the queue
        // @return : the element at the front
        virtual E dequeue() = 0;

        // @return : a copy of the front element
        virtual E frontValue() = 0;

        // @return : the number of elements in the queue
        virtual int length() = 0;

    private:
};

#endif