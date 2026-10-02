#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

template <class T>
class clsQueue : protected clsDbLinkedList<T>
{
public:
    void print()
    {
        this->printList();
    }

    void push(T value)
    {
        this->insertAtEnd(value);
    }

    void pop()
    {
        this->deleteFirstNode();
    }

    int size()
    {
        return clsDbLinkedList<T>::size();
    }

    T front()
    {
        return this->getItem(0);
    }

    T back()
    {
        return this->getItem(clsDbLinkedList<T>::size() - 1);
    }
};
