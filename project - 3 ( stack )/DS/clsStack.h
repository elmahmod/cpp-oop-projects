#pragma once
#include <iostream>
#include "clsQueue.h"
using namespace std;

template <class T>
class clsStack : public clsQueue<T>
{
private:
public:
    void push(T value)
    {
        clsQueue<T>::_myList.insertAtBeginning(value);
        // this->_myList.insertAtBeginning(value);
    }

    T top()
    {
        return this->front();
    }

    T bottom()
    {
        return this->back();
    }
};