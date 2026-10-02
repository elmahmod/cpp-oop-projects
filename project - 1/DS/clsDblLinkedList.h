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
    int _size = 0;

public:
    ~clsDbLinkedList()
    {
        clear();
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

        _size++;
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

        _size++;
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

        _size++;
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

        _size--;
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

        _size--;
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
            _size--;
            return;
        }

        lastNode->prev->next = nullptr;
        delete lastNode;

        _size--;
    }

    // Big O(n)
    /*
    int _size()
    {
        Node *temp = head;
        int counter = 0;
        while (temp != nullptr)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    */

    // Big O(1) by using _size value
    int size()
    {
        return _size;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void clear()
    {
        while (!isEmpty())
            deleteFirstNode();
    }

    void reverse()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *temp = nullptr;
        Node *current = head;

        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            current = current->prev;
        }

        head = temp->prev;
    }

    Node *getNode(int index)
    {
        if (index < 0 || index >= _size)
            return nullptr;

        int counter = 0;
        Node *temp = head;

        while (temp != nullptr)
        {
            if (index == counter)
                break;

            counter++;
            temp = temp->next;
        }

        return temp;
    }

    T getItem(int index)
    {
        Node *n = getNode(index);
        if (n == nullptr)
            return T{};
        return n->value;
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