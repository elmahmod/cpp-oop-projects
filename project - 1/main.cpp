#include <iostream>
#include "DS/clsDblLinkedList.h"
using namespace std;

int main()
{
    clsDbLinkedList<int> myDblLinkedList;

    myDblLinkedList.insertAtBeginning(4);
    myDblLinkedList.insertAtBeginning(3);
    myDblLinkedList.insertAtBeginning(2);
    myDblLinkedList.insertAtBeginning(1);

    cout << "\nLinked List elements: ";
    myDblLinkedList.printList();

    clsDbLinkedList<int>::Node *n1 = myDblLinkedList.find(4);

    if (n1 != nullptr)
        cout << "\nNode with value 4 is found\n";
    else
        cout << "\nNode is not found\n";

    cout << "\nInserting 5 after 4\n";
    myDblLinkedList.insertAfter(n1, 5);
    myDblLinkedList.printList();

    cout << "\nAfter deleting 4\n";
    myDblLinkedList.deleteNode(n1);
    n1 = nullptr; // Prevent dangling pointer
    myDblLinkedList.printList();

    cout << "\nAfter deleting first Node\n";
    myDblLinkedList.deleteFirstNode();
    myDblLinkedList.printList();

    cout << "\nAfter deleting last Node\n";
    myDblLinkedList.deleteLastNode();
    myDblLinkedList.printList();

    cout << "\nInserting 6 at the end\n";
    myDblLinkedList.insertAtEnd(6);
    myDblLinkedList.printList();

    cout << "\nSize: " << myDblLinkedList.size() << endl;

    if (myDblLinkedList.isEmpty())
        cout << "\nyes it is empty\n";
    else
        cout << "\nno it is not empty\n";
        
    return 0;
}
