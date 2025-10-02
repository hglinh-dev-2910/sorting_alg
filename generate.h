#ifndef GENERATE_H
#define GENERATE_H

struct Node {
    int value;
    Node* pNext;
};

void pushBack(Node*& pHead ,int pValue);
Node* generateRandomList(int n);

void printList(Node* pHead);



#endif