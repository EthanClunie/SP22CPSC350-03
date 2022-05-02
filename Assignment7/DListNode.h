// abstract list node class with 2 pointers

#ifndef DLISTNODE_H
#define DLISTNODE_H

template <typename E>
class DListNode
{
  public:
    E element;
    DListNode* prev; // pointer to previous node
    DListNode* next; // pointer to next node

    /*
    Constructor initializes prev and next pointers
    */
    DListNode()
    {
      prev = nullptr;
      next = nullptr;
    }

    /*
    Overloaded constructor initializes prev and next pointers and sets value of element
    @param elemVal: data value to be added to node
    */
    DListNode(E elemVal)
    {
      element = elemVal;
      prev = nullptr;
      next = nullptr;
    }

    // Destructor of ListNode objects
    ~DListNode(){};
};

#endif