/**
 * @file DLQueue.h
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Class definition and implementation for a generic queue using a doubly-linked list
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef DLQUEUE_H
#define DLQUEUE_H

#include "Queue.h"
#include "DLList.h"
#include <iostream>

using namespace std;

template <typename E>

class DLQueue : public Queue<E>
{
    private:
        DLList<E> *doublyLinkedList;

    public:
        DLQueue();
        ~DLQueue();

        void clear();
        void enqueue(const E& item);
        E dequeue();
        E frontValue();
        int length();

        bool isEmpty();

};


template <typename E>
DLQueue<E>::DLQueue()
{
    doublyLinkedList = new DLList<E>;
}


template <typename E>
DLQueue<E>::~DLQueue()
{
    delete doublyLinkedList;
}


template <typename E>
void DLQueue<E>::clear()
{
    while (!doublyLinkedList->isEmpty())
    {
        doublyLinkedList->removeBack();
    }

}


template <typename E>
void DLQueue<E>::enqueue(const E& item)
{
    doublyLinkedList->insertBack(item);
}


template <typename E>
E DLQueue<E>::dequeue()
{
    if (doublyLinkedList->isEmpty())
    {
        string lineWithError = to_string(__LINE__);
        string fileWithError = __FILE__;
        throw runtime_error("ERROR: Empty queue. Cannot remove. Loc: (File: "+fileWithError+", Line: "+lineWithError+")");
    }

    return doublyLinkedList->removeFront();
}


template <typename E>
E DLQueue<E>::frontValue()
{
    if (doublyLinkedList->isEmpty())
    {
        E *item = new E();
        return *item;
    }
    
    return doublyLinkedList->peekFront();
}


template <typename E>
int DLQueue<E>::length()
{
    return doublyLinkedList->length();
}


template <typename E>
bool DLQueue<E>::isEmpty()
{
    return doublyLinkedList->isEmpty();
}

#endif