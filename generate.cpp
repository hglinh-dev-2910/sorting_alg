#include "generate.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

void pushBack(Node *&pHead, int pValue)
{
    Node *newNode = new Node(); // create newNode to push back

    newNode->value = pValue;
    newNode->pNext = nullptr;

    if (pHead == nullptr)
    { // check if list is empty
        pHead = newNode;
    }
    else
    {
        Node *temp = pHead; // create a temp node

        while (temp->pNext != nullptr)
        {
            temp = temp->pNext; // move forward to last node
        }

        temp->pNext = newNode; // push newNode to list (behind last Node)
    }
}

Node *generateRandomList(int n) // return a new list with n-elements
{
    Node *pHead = nullptr;
    srand(time(0)); // generate difference seeds

    for (int i = 0; i < n; i++)
    {
        int randValue = rand() % n; // create random value from 0-n
        pushBack(pHead, randValue);   // pushBack to list
    }

    return pHead;
}

void printList(Node *pHead)
{
    if (pHead == nullptr)
    { // check if list is empty
        std::cout << "List is empty" << std::endl;
    }
    else
    {
        Node *temp = pHead;
        int counter = 0; // count number of node in list
        while (temp != nullptr)
        {
            std::cout << "Value at node " << counter<< " is: " << temp->value << std::endl;
            counter++; // increase counter value
            temp = temp->pNext; // move pointer to next node
        }
    }
}
