// stack abstract class

#ifndef STACK_H
#define STACK_H

template <typename E>

class Stack
{
    public:
        Stack() {} // default constructor
        virtual ~Stack() {} // base destructor

        // reinitializes the stack
        virtual void clear() = 0;

        // push an element onto the top of the stack
        // @param item: element to be pushed
        virtual void push(const E& item) = 0;

        // remove the element from the top of the stack
        // @return : the element at the top
        virtual E pop() = 0;

        // return a copy of the top element
        // @return : a copy of the element at the top
        virtual E topValue() = 0;

        // return the number of elements in the stack
        // @return : the "length" of the stack
        virtual int length() = 0;
    private:

};

#endif