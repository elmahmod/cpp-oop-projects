#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDbLinkedList
{
private:
    class Node
    {
    public:
        T value;
        Node *prev;
        Node *next;
    };
    Node *head = nullptr;

public:
    clsDbLinkedList()
    {
    }

    void insertAtBeginning(T value)
    {
        Node *newNode = new Node();

        newNode->value = value;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
    }

    void printList()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};