#include <iostream>
#include "DS/clsDynamicArray.h"
using namespace std;

int main()
{
    clsDynamicArray<int> myDynamicArray(10);

    cout << "\n== Initial Dynamic Array ==\n";
    myDynamicArray.setItem(0, 10);
    myDynamicArray.setItem(1, 20);
    myDynamicArray.setItem(2, 30);
    myDynamicArray.setItem(3, 40);
    myDynamicArray.setItem(4, 50);

    cout << "Array Items: ";
    myDynamicArray.printList();

    cout << "\n== Array Informatiomn ==\n";
    cout << "Size     : " << myDynamicArray.size() << endl;
    cout << "Is empty : " << myDynamicArray.isEmpty() << endl;
    return 0;
}