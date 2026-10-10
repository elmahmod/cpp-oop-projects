#include <iostream>
#include "DS/clsDynamicArray.h"
using namespace std;

int main()
{
    clsDynamicArray<int> myDynamicArray(5);

    cout << "\n===== Initial Dynamic Array =====\n";

    myDynamicArray.setItem(0, 10);
    myDynamicArray.setItem(1, 20);
    myDynamicArray.setItem(2, 30);
    myDynamicArray.setItem(3, 40);
    myDynamicArray.setItem(4, 50);

    cout << "Array: ";
    myDynamicArray.printList();

    cout << "\n===== Array Information =====\n";
    cout << "Size    : " << myDynamicArray.size() << endl;
    cout << "Is Empty: " << boolalpha
         << myDynamicArray.isEmpty() << endl;

    cout << "\n===== Resize to 2 =====\n";
    myDynamicArray.resize(2);

    cout << "Array: ";
    myDynamicArray.printList();
    cout << "Size : " << myDynamicArray.size() << endl;

    cout << "\n===== Resize to 10 =====\n";
    myDynamicArray.resize(10);

    cout << "Array: ";
    myDynamicArray.printList();
    cout << "Size : " << myDynamicArray.size() << endl;

    cout << "\n===== Resize to 0 =====\n";
    myDynamicArray.resize(0);

    cout << "Size    : " << myDynamicArray.size() << endl;
    cout << "Is Empty: " << boolalpha
         << myDynamicArray.isEmpty() << endl;
    return 0;
}