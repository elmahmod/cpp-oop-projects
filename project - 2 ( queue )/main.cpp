#include <iostream>
#include "DS/clsQueue.h"
using namespace std;

int main()
{
    clsQueue<int> myQueue;

    cout << "\n===== Initial Queue =====\n";
    cout << "Queue: ";
    myQueue.print();

    cout << "\n===== Push Elements =====\n";

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);

    cout << "Queue: ";
    myQueue.print();

    cout << "\n===== Queue Information =====\n";
    cout << "Size : " << myQueue.size() << endl;
    cout << "Front: " << myQueue.front() << endl;
    cout << "Back : " << myQueue.back() << endl;

    cout << "\n===== Get Item =====\n";
    cout << "Item at index 2: " << myQueue.getItem(2) << endl;

    cout << "\n===== Update Item =====\n";
    cout << "Before update: ";
    myQueue.print();

    myQueue.updateItem(1, 100);

    cout << "After updating index 1 to 100: ";
    myQueue.print();

    cout << "\n===== Insert After =====\n";
    cout << "Before insert: ";
    myQueue.print();

    myQueue.insertAfter(1, 200);

    cout << "After inserting 200 after index 1: ";
    myQueue.print();

    cout << "\n===== Reverse =====\n";
    cout << "Before reverse: ";
    myQueue.print();

    myQueue.reverse();

    cout << "After reverse : ";
    myQueue.print();

    cout << "\n===== Pop =====\n";
    cout << "Removing front element...\n";

    myQueue.pop();

    cout << "Queue: ";
    myQueue.print();

    cout << "\n===== Queue Information After Pop =====\n";
    cout << "Size : " << myQueue.size() << endl;
    cout << "Front: " << myQueue.front() << endl;
    cout << "Back : " << myQueue.back() << endl;

    cout << "\n========================\n";
    cout << "Program finished.\n";
    cout << "========================\n";

    return 0;
}