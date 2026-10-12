#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
protected:
    T *orgArray = nullptr;
    T *_tempArray = nullptr;
    int _size = 0;

public:
    clsDynamicArray(int size = 0)
    {
        if (size < 0)
            size = 0;

        _size = size;
        orgArray = new T[_size]{};
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

    T getItem(int index)
    {
        if (index < 0 || index >= _size)
            return T{};
        return orgArray[index];
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
        if (orgArray == nullptr)
            return;

        for (int i = 0; i < _size; i++)
        {
            cout << orgArray[i] << " ";
        }
        cout << "\n";
    }

    void resize(int size)
    {
        if (size < 0)
            size = 0;

        _tempArray = new T[size]{};

        int elementsToCopy = std::min(_size, size);

        for (int i = 0; i < elementsToCopy; i++)
        {
            _tempArray[i] = orgArray[i];
        }

        delete[] orgArray;

        orgArray = _tempArray;
        _size = size;
    }

    void reverse()
    {
        if (_size == 0 || _size == 1)
            return;

        _tempArray = new T[_size];

        for (int i = 0; i < _size; i++)
        {
            _tempArray[i] = orgArray[_size - 1 - i];
        }

        delete[] orgArray;
        orgArray = _tempArray;
    }

    // void reverse()
    // {
    //     if (_size <= 1)
    //         return;

    //     for (int i = 0; i < _size / 2; i++)
    //     {
    //         T temp = orgArray[i];

    //         orgArray[i] = orgArray[_size - 1 - i];

    //         orgArray[_size - 1 - i] = temp;
    //     }
    // }

    void clear()
    {
        _size = 0;
        delete[] orgArray;
        orgArray = nullptr;
    }

    // void deleteItemAt(int index)
    // {
    //     if (index < 0 || index >= _size)
    //         return;

    //     _tempArray = new T[_size - 1];

    //     int elementsToCopy = 0;

    //     for (int i = 0; i < _size; i++)
    //     {
    //         if (index == i)
    //             continue;

    //         _tempArray[elementsToCopy] = orgArray[i];
    //         elementsToCopy++;
    //     }

    //     _size -= 1;
    //     delete[] orgArray;
    //     orgArray = _tempArray;
    // }

    bool deleteItemAt(int index)
    {
        if (index < 0 || index >= _size)
            return false;

        int newSize = _size - 1;

        _tempArray = new T[newSize];

        // copy before index
        for (int i = 0; i < index; i++)
        {
            _tempArray[i] = orgArray[i];
        }

        // copy after index;
        for (int i = index; i < newSize; i++)
        {
            _tempArray[i] = orgArray[i + 1];
        }

        delete[] orgArray;
        orgArray = _tempArray;
        _size = newSize;
        return true;
    }
};