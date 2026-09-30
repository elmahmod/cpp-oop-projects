#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDbLinkedList
{
public:
    class Node
    {
    public:
        T value;
        Node *prev;
        Node *next;
    };

private:
    Node *head = nullptr;

public:
    ~clsDbLinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
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

    Node *find(T value)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->value == value)
                return temp;

            temp = temp->next;
        }
        return nullptr;
    }

    void insertAfter(Node *currentNode, T value)
    {
        if (head == nullptr || currentNode == nullptr)
            return;

        Node *newNode = new Node();
        newNode->value = value;
        newNode->next = currentNode->next;
        newNode->prev = currentNode;

        if (currentNode->next != nullptr)
            currentNode->next->prev = newNode;

        currentNode->next = newNode;
    }

    void insertAtEnd(T value)
    {
        if (head == nullptr)
        {
            insertAtBeginning(value);
            return;
        }

        Node *newNode = new Node();
        newNode->value = value;

        Node *lastNode = head;
        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }

        newNode->next = lastNode->next;
        newNode->prev = lastNode;

        lastNode->next = newNode;
    }

    void deleteNode(Node *toDelete)
    {
        if (head == nullptr || toDelete == nullptr)
            return;

        if (toDelete == head)
        {
            head = toDelete->next;
        }

        if (toDelete->prev != nullptr)
        {
            toDelete->prev->next = toDelete->next;
        }

        if (toDelete->next != nullptr)
        {
            toDelete->next->prev = toDelete->prev;
        }

        delete toDelete;
    }

    void deleteFirstNode()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;

        delete temp;
    }

    void deleteLastNode()
    {
        if (head == nullptr)
            return;

        Node *lastNode = head;
        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }

        if (lastNode->prev == nullptr)
        {
            head = nullptr;
            delete lastNode;
            return;
        }

        lastNode->prev->next = nullptr;
        delete lastNode;
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