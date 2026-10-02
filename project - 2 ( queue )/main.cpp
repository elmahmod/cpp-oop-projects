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
