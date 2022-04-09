// doubly linked list template class

#ifndef DLLIST_H
#define DLLIST_H

#include "DListNode.h"

template <typename E>
class DLList
{
  private:
    DListNode<E>* head; // pointer to front of list
    DListNode<E>* tail; // pointer to back of list
    int size; // number of elements in list

  public:
    DLList();
    ~DLList();
    void insertFront(E item);
    void insertBack(E item);
    E removeFront();
    E removeBack();
    E peekFront();
    E peekBack();
    int length();
    bool isEmpty();
};

/*
Constructor for DLList.
*/
template <typename E>
DLList<E>::DLList()
{
  head = nullptr;
  tail = nullptr;
  size = 0;
}

/*
Destructor for DLList.
*/
template <typename E>
DLList<E>::~DLList()
{
  if (size == 0)
  {
    // Do nothing
  }
  else
  {
    DListNode<E>* temp = tail;
    while (head != nullptr)
    {
      temp = head;
      head = head->next;
      delete temp;
    }
  }

}

/*
insertFront
Function inserts a list node to the front of the list.
@param item: item value to be inserted.
*/
template <typename E>
void DLList<E>::insertFront(E item)
{
  DListNode<E>* temp = new DListNode<E>(item);
  if (size == 0)
  {
    tail = temp;
  }
  else
  {
    head->prev = temp;
    temp->next = head;
  }
  head = temp;
  size++;
}

/*
insertBack
Function inserts a list node to the back of the list.
@param item: item value to be inserted.
*/
template <typename E>
void DLList<E>::insertBack(E item)
{
  DListNode<E>* temp = new DListNode<E>(item);
  if (size == 0)
  {
    head = tail = temp;
  }
  else
  {
    tail->next = temp;
    temp->prev = tail;
  }
  tail = temp;
  size++;
}

/*
removeFront
Function removes a list node from the front of the list.
@return: item value at front.
*/
template <typename E>
E DLList<E>::removeFront()
{
  DListNode<E>* temp = head;

  if (head->next == nullptr)
  {
    tail = nullptr;
  }
  else
  {
    head->next->prev = nullptr;
    head = head->next;
  }
  E item = temp->element;
  temp->next = nullptr;

  delete temp;
  if (size > 0)
  {
    size--;
  }
  
  return item;
}


/*
removeBack
Function removes a list node from the back of the list.
@return: item value at back.
*/
template <typename E>
E DLList<E>::removeBack()
{
  DListNode<E>* temp = tail;

  if (tail->prev == nullptr)
  {
    head = nullptr;
  }
  else
  {
    temp->prev->next = nullptr;
    tail = tail->prev;
  }
  E item = temp->element;
  temp->prev = nullptr;

  delete temp;
  if (size > 0)
  {
    size--;
  }
  
  return item;
}

/*
peekFront
Function returns the data value at front of list
@return: item value at front.
*/
template <typename E>
E DLList<E>::peekFront()
{
  return head->element;
}

/*
peekBack
Function returns the data value at the back of list
@return: item value at back.
*/
template <typename E>
E DLList<E>::peekBack()
{
  return tail->element;
}

/*
length
Function returns the size of the list.
@return: size of list.
*/
template <typename E>
int DLList<E>::length()
{
  return size;
}


/*
length
Function returns if list is empty or not by checking size.
@return: T/F.
*/
template <typename E>
bool DLList<E>::isEmpty()
{
  return (size == 0);
}

#endif