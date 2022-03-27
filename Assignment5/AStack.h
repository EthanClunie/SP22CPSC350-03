/**
 * @file AStack.h
 * @author Ethan Clunie
 * @brief Contains both the definitions and implementations of methods needed to create and 
 * manipulate an array-based stack by inheriting the necessary methods from the virtual Stack<E> class.
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

template <typename E>

class AStack : public Stack<E>
{
    private:
        int stackSize;
        int maxSize;

        int top;
        E* stackArray;

        void resizeStack();

    public:
        AStack(int size);
        ~AStack();

        void clear();
        void push(const E& item);
        E pop();
        E topValue();
        int length();

};

template <typename E>
AStack<E>::AStack(int size)
{
    maxSize = size;
    stackSize = top = 0;
    stackArray = new E[maxSize];
}


template <typename E>
AStack<E>::~AStack()
{
    delete[] stackArray;
}


template <typename E>
void AStack<E>::clear()
{
    delete[] stackArray;
    stackSize = top = 0;
    stackArray = new E[maxSize];
}


template <typename E>
void AStack<E>::push(const E& item)
{
    if (stackSize >= maxSize)
    {
        resizeStack();
    }

    stackArray[++top] = item;
    ++stackSize;
}


template <typename E>
E AStack<E>::pop()
{
    if (stackSize == 0) 
    {
        // Need to throw an exception
        string fileWithError = __FILE__;
        throw runtime_error("ArrayStack length = 0; cannot pop(), Loc: (File: " + fileWithError + ", Line: " + to_string(__LINE__) + ")");
    }

    E item = stackArray[top];

    top--;
    stackSize--;
    return item;
}


template <typename E>
E AStack<E>::topValue()
{
    return stackArray[top];
}


template <typename E>
int AStack<E>::length()
{
    return stackSize;
}


template <typename E>
void AStack<E>::resizeStack()
{
    // Create a new array of size maxSize^2, if maxSize > 1;
    E* newStackArray;
    if (maxSize == 1)
    {
        E* newStackArray = new E[maxSize + maxSize];
    }
    else
    {
        E* newStackArray = new E[maxSize*maxSize];
    }

    // Copy contents from stackArray to newStackArray
    for (int i = 0; i < stackSize; i++)
    {
        newStackArray[i] = stackArray[i];
        cout << newStackArray[i] << endl;
    }
    newStackArray[top] = stackArray[top];

    // Delete the old stack array and recreate it with new maxSize (= maxSize^2)
    delete[] stackArray;
    stackArray = new E[maxSize];

    // Copy contents from newStackArray to stackArray
    for (int i = 0; i < stackSize; i++)
    {
        stackArray[i] = newStackArray[i];
    }

    // Handle changing the value of maxSize
    if (maxSize == 1)
    {
        maxSize = maxSize + maxSize;
    }
    else
    {
        maxSize = maxSize * maxSize;
    }
    
    // Delete the temporary "newStackArray"
    delete[] newStackArray;
}

#endif