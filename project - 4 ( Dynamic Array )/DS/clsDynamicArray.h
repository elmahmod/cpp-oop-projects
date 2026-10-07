#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
protected:
    T *orgArray = nullptr;
    int _size = 0;

public:
    clsDynamicArray(int size = 0)
    {
        if (size < 0)
            size = 0;

        _size = size;
        orgArray = new T[_size];
    }

    ~clsDynamicArray()
    {
        delete[] orgArray;
    }

    bool setItem(int index, T value)
    {
        if (index < 0 || index >= _size)
            return false;

        orgArray[index] = value;
        return true;
    }

    bool isEmpty()
    {
        return _size == 0;
    }

    int size()
    {
        return _size;
    }

    void printList()
    {
        for (int i = 0; i < _size; i++)
        {
            cout << orgArray[i] << " ";
        }
        cout << "\n";
    }
};