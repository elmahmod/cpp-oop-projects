#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsQueueArr
{
protected:
    clsDynamicArray<T> _myArr;

public:
    void print()
    {
        _myArr.printList();
    }

    void push(T value)
    {
        _myArr.insertAtEnd(value);
    }

    void pop()
    {
        _myArr.deleteFirstItem();
    }

    int size()
    {
        return _myArr.size();
    }

    T front()
    {
        return _myArr.getItem(0);
    }

    T back()
    {
        return _myArr.getItem(_myArr.size() - 1);
    }

    bool isEmpty()
    {
        return _myArr.isEmpty();
    }

    T getItem(int index)
    {
        return _myArr.getItem(index);
    }

    void reverse()
    {
        _myArr.reverse();
    }

    void updateItem(int index, T value)
    {
        _myArr.setItem(index, value);
    }

    void insertAfter(int index, T value)
    {
        _myArr.insertAfter(index, value);
    }

    void insertAtFront(T value)
    {
        _myArr.insertAtBeginning(value);
    }

    void insertAtEnd(T value)
    {
        _myArr.insertAtEnd(value);
    }

    void clear()
    {
        _myArr.clear();
    }
};
