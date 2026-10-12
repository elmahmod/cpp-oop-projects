#pragma once
#include <iostream>
#include "clsQueueArr.h"
using namespace std;

template <class T>
class clsStackArr : public clsQueueArr<T>
{
private:
public:
    void push(T value)
    {
        clsQueueArr<T>::_myArr.insertAtBeginning(value);
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