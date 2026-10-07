#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

template <class T>
class clsQueue
{
protected:
    clsDbLinkedList<T> _myList;

public:
    void print()
    {
        _myList.printList();
    }

    void push(T value)
    {
        _myList.insertAtEnd(value);
    }

    void pop()
    {
        _myList.deleteFirstNode();
    }

    int size()
    {
        return _myList.size();
    }

    T front()
    {
        return _myList.getItem(0);
    }

    T back()
    {
        return _myList.getItem(_myList.size() - 1);
    }

    bool isEmpty()
    {
        return _myList.isEmpty();
    }

    T getItem(int index)
    {
        return _myList.getItem(index);
    }

    void reverse()
    {
        _myList.reverse();
    }

    void updateItem(int index, T value)
    {
        _myList.updateItem(index, value);
    }

    void insertAfter(int index, T value)
    {
        _myList.insertAfter(index, value);
    }

    void insertAtFront(T value)
    {
        _myList.insertAtBeginning(value);
    }

    void insertAtEnd(T value)
    {
        _myList.insertAtEnd(value);
    }

    void clear()
    {
        _myList.clear();
    }
};
