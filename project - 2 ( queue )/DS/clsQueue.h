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
};
