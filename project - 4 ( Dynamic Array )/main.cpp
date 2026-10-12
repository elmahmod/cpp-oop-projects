#include <iostream>
#include "DS/clsDynamicArray.h"
using namespace std;

int main()
{
    clsDynamicArray<float> myDynamicArray(5);

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

    cout << "\n===== Resize to 4 =====\n";
    myDynamicArray.resize(4);

    cout << "Array: ";
    myDynamicArray.printList();
    cout << "Size : " << myDynamicArray.size() << endl;

    // cout << "\n===== Resize to 10 =====\n";
    // myDynamicArray.resize(10);

    // cout << "Array: ";
    // myDynamicArray.printList();
    // cout << "Size : " << myDynamicArray.size() << endl;

    // cout << "\n===== Resize to 0 =====\n";
    // myDynamicArray.resize(0);

    // cout << "Size    : " << myDynamicArray.size() << endl;
    // cout << "Is Empty: " << boolalpha
    //      << myDynamicArray.isEmpty() << endl;

    cout << "\n==== Reverse ====\n";
    cout << "Before: ";
    myDynamicArray.printList();

    myDynamicArray.reverse();

    cout << "After: ";
    myDynamicArray.printList();

    // cout << "\n==== Clear ====\n";
    // myDynamicArray.clear();
    // myDynamicArray.printList();
    // cout << "Size    : " << myDynamicArray.size() << endl;

    cout << "\n==== Delete Item At[2] ====\n";
    cout << "Before: ";
    myDynamicArray.printList();

    myDynamicArray.deleteItemAt(2);

    cout << "After: ";
    myDynamicArray.printList();

    // cout << "\n==== Delete First Item ====\n";
    // cout << "Before: ";
    // myDynamicArray.printList();

    // myDynamicArray.deleteFirstItem();

    // cout << "After: ";
    // myDynamicArray.printList();

    // cout << "\n==== Delete Last Item ====\n";
    // cout << "Before: ";
    // myDynamicArray.printList();

    // myDynamicArray.deleteLastItem();

    // cout << "After: ";
    // myDynamicArray.printList();

    // cout << "\n==== Find Item ====\n";
    // cout << "Array: ";
    // myDynamicArray.printList();

    // int index = myDynamicArray.find(30);

    // if (index == -1)
    //     cout << "Item 30 not found!" << endl;
    // else
    //     cout << "Item 30 found at index: " << index << endl;

    // index = myDynamicArray.find(100);

    // if (index == -1)
    //     cout << "Item 100 not found!" << endl;
    // else
    //     cout << "Item 100 found at index: " << index << endl;

    // cout << "\n==== Delete Item (30) ====\n";
    // cout << "Before: ";
    // myDynamicArray.printList();

    // bool isDeleted = myDynamicArray.deleteItem(30);
    // cout << "Deleted: " << boolalpha << isDeleted << endl;

    // cout << "After: ";
    // myDynamicArray.printList();

    // cout << "\n==== Delete Item (100) ====\n";
    // cout << "Before: ";
    // myDynamicArray.printList();

    // isDeleted = myDynamicArray.deleteItem(100);
    // cout << "Deleted: " << boolalpha << isDeleted << endl;

    // cout << "After: ";
    // myDynamicArray.printList();

    cout << "\n==== Insert Item At[2] ====\n";
    cout << "Before: ";
    myDynamicArray.printList();

    bool isInserted = myDynamicArray.insertAt(2, 60);
    cout << "Inserted: " << boolalpha << isInserted << endl;

    cout << "After: ";
    myDynamicArray.printList();

    cout << "\n==== Insert At Beginning (5) ====\n";
    cout << "Before: ";
    myDynamicArray.printList();

    isInserted = myDynamicArray.insertAtBeginning(5);
    cout << "Inserted: " << boolalpha << isInserted << endl;

    cout << "After: ";
    myDynamicArray.printList();

    cout << "\n==== Insert At End (70) ====\n";
    cout << "Before: ";
    myDynamicArray.printList();

    isInserted = myDynamicArray.insertAtEnd(70);
    cout << "Inserted: " << boolalpha << isInserted << endl;

    cout << "After: ";
    myDynamicArray.printList();

    cout << "\n==== Insert Before Index[2] (25) ====\n";
    cout << "Before: ";
    myDynamicArray.printList();

    isInserted = myDynamicArray.insertBefore(2, 25);
    cout << "Inserted: " << boolalpha << isInserted << endl;

    cout << "After: ";
    myDynamicArray.printList();

    cout << "\n==== Insert After Index[3] (35) ====\n";
    cout << "Before: ";
    myDynamicArray.printList();

    isInserted = myDynamicArray.insertAfter(3, 35);
    cout << "Inserted: " << boolalpha << isInserted << endl;

    cout << "After: ";
    myDynamicArray.printList();

    cout << "\n===== Final Array Information =====\n";
    cout << "Array: ";
    myDynamicArray.printList();
    cout << "Size    : " << myDynamicArray.size() << endl;
    cout << "Is Empty: " << boolalpha << myDynamicArray.isEmpty() << endl;

    return 0;
}