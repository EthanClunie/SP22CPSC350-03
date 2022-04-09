// ListNode for a singly linked list

#ifndef LISTNODE_H
#define LISTNODE_H

template <typename E>

class ListNode
{
    public:
        E element; // value of a node
        ListNode* next; // pointer to the next node in the list

        ListNode(E elemVal, ListNode* nextVal = nullptr)
        {
            element = elemVal;
            next = nextVal;
        }

        ListNode(ListNode* nextVal = nullptr) 
        {
            next = nextVal;
        }

        
};

#endif