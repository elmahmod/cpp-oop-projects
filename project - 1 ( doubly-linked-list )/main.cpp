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

    cout << "\n===== Initial List =====\n";
    cout << "List: ";
    myDblLinkedList.printList();

    cout << "\n===== Find Node =====\n";
    clsDbLinkedList<int>::Node *n1 = myDblLinkedList.find(4);

    if (n1 != nullptr)
        cout << "Node with value 4 was found.\n";
    else
        cout << "Node with value 4 was not found.\n";

    cout << "\n===== Insert After Node =====\n";
    cout << "Inserting 5 after 4...\n";
    myDblLinkedList.insertAfter(n1, 5);

    cout << "List: ";
    myDblLinkedList.printList();

    cout << "\n===== Delete Node =====\n";
    cout << "Deleting node with value 4...\n";
    myDblLinkedList.deleteNode(n1);
    n1 = nullptr;

    cout << "List: ";
    myDblLinkedList.printList();

    cout << "\n===== Delete First Node =====\n";
    myDblLinkedList.deleteFirstNode();

    cout << "List: ";
    myDblLinkedList.printList();

    cout << "\n===== Delete Last Node =====\n";
    myDblLinkedList.deleteLastNode();

    cout << "List: ";
    myDblLinkedList.printList();

    cout << "\n===== Insert At End =====\n";
    cout << "Inserting 6 at the end...\n";
    myDblLinkedList.insertAtEnd(6);

    cout << "List: ";
    myDblLinkedList.printList();

    cout << "\n===== List Information =====\n";
    cout << "Size: " << myDblLinkedList.size() << endl;
    cout << "Is empty: "
         << (myDblLinkedList.isEmpty() ? "Yes" : "No")
         << endl;

    cout << "\n===== Reverse List =====\n";
    cout << "Before reverse: ";
    myDblLinkedList.printList();

    myDblLinkedList.reverse();

    cout << "After reverse : ";
    myDblLinkedList.printList();

    cout << "\n===== Get Node By Index =====\n";
    n1 = myDblLinkedList.getNode(1);

    if (n1 != nullptr)
    {
        cout << "Node at index 1 was found.\n";
        cout << "Value: " << n1->value << endl;
    }
    else
    {
        cout << "Node at index 1 was not found.\n";
    }

    cout << "\n===== Get Item =====\n";
    cout << "Item at index 1: "
         << myDblLinkedList.getItem(1)
         << endl;

    cout << "\n===== Update Item =====\n";

    if (myDblLinkedList.updateItem(1, 500))
    {
        cout << "Item at index 1 was updated successfully.\n";
        cout << "New value: "
             << myDblLinkedList.getItem(1)
             << endl;
    }
    else
    {
        cout << "Failed to update item.\n";
    }

    cout << "\n===== Insert After Index =====\n";
    cout << "Inserting 1 after index 2...\n";
    myDblLinkedList.insertAfter(2, 1);

    cout << "List: ";
    myDblLinkedList.printList();

    cout << "\n===== Clear List =====\n";
    cout << "Size before clearing: "
         << myDblLinkedList.size()
         << endl;

    myDblLinkedList.clear();

    cout << "Size after clearing : "
         << myDblLinkedList.size()
         << endl;

    cout << "\n========================\n";
    cout << "Program finished.\n";
    cout << "========================\n";

    return 0;
}