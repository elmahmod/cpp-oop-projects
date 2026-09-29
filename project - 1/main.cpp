#include <iostream>
#include "DS/clsDblLinkedList.h"
using namespace std;

int main()
{
    clsDbLinkedList<int> myDblLinkedList;

    myDblLinkedList.insertAtBeginning(1);
    myDblLinkedList.insertAtBeginning(1);
    myDblLinkedList.insertAtBeginning(1);

    myDblLinkedList.printList();
    return 0;
}
