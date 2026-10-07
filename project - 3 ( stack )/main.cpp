#include <iostream>
#include "DS/clsStack.h"
using namespace std;

int main()
{
    clsStack<int> myStack;

    cout << "\n===== Initial Stack =====\n";
    cout << "Stack: ";
    myStack.print();

    cout << "\n===== Push Elements =====\n";

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    cout << "Stack: ";
    myStack.print();

    cout << "\n===== Stack Information =====\n";
    cout << "Size  : " << myStack.size() << endl;
    cout << "Top   : " << myStack.top() << endl;
    cout << "Bottom: " << myStack.bottom() << endl;

    cout << "\n===== Get Item =====\n";
    cout << "Item at index 2: " << myStack.getItem(2) << endl;

    cout << "\n===== Update Item =====\n";
    cout << "Before update: ";
    myStack.print();

    myStack.updateItem(1, 100);

    cout << "After updating index 1 to 100: ";
    myStack.print();

    cout << "\n===== Insert After =====\n";
    cout << "Before insert: ";
    myStack.print();

    myStack.insertAfter(1, 200);

    cout << "After inserting 200 after index 1: ";
    myStack.print();

    cout << "\n===== Reverse =====\n";
    cout << "Before reverse: ";
    myStack.print();

    myStack.reverse();

    cout << "After reverse : ";
    myStack.print();

    cout << "\n===== Pop =====\n";
    cout << "Removing top element...\n";

    myStack.pop();

    cout << "Stack: ";
    myStack.print();

    cout << "\n===== Stack Information After Pop =====\n";
    cout << "Size  : " << myStack.size() << endl;
    cout << "Top   : " << myStack.front() << endl;
    cout << "Bottom: " << myStack.back() << endl;

    cout << "\n========================\n";
    cout << "Program finished.\n";
    cout << "========================\n";

    return 0;
}