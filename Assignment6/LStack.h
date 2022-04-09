#ifndef LSTACK_H
#define LSTACK_H

#include "Stack.h"
#include "ListNode.h"

template <typename E>

class LStack : public Stack<E>
{
    private:
        ListNode<E>* top; // pointer to the top element in the stack
        int size; // number of elements in the stack

    public:
        LStack(int sz);
        ~LStack();
        void clear();
        void push(const E& item);
        E pop();
        E topValue();
        int length();

};

template <typename E>
LStack<E>::LStack(int sz) // sz used for ArrayStack not LinkedStack
{
    top = nullptr;
    size = 0;
}

template <typename E>
LStack<E>::~LStack()
{
    clear();
}

template <typename E>
void LStack<E>::clear()
{
    while (top != nullptr)
    {
        ListNode<E>* temp = top;
        top = top->next;
        delete temp;
    }

    size = 0;
}

template <typename E>
void LStack<E>::push(const E& item)
{
    // new temp list node
    // temp->next = top
    // top = temp
    top = new ListNode<E>(item, top);

    size++;
}

template <typename E>
E LStack<E>::pop()
{
    if (top == nullptr) // Edge case handling for empty Stack
    {
        E value = E();
        return value;
    }

    E item = top->element;
    ListNode<E>* temp = top->next;

    delete top;
    top = temp;

    size--;
    return item;
}

template <typename E>
E LStack<E>::topValue()
{
    if (top == nullptr) // Edge case handling for empty Stack
    {
        E value = E();
        return value;
    }
    
    return top->element;
}

template <typename E>
int LStack<E>::length()
{
    return size;
}

#endif