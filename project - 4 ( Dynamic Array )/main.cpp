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
    
    cout << "\n==== Delete First Item ====\n";
    cout << "Before: ";
    myDynamicArray.printList();

    myDynamicArray.deleteFirstItem();

    cout << "After: ";
    myDynamicArray.printList();

        cout << "\n==== Delete Last Item ====\n";
    cout << "Before: ";
    myDynamicArray.printList();

    myDynamicArray.deleteLastItem();

    cout << "After: ";
    myDynamicArray.printList();
    return 0;
}
