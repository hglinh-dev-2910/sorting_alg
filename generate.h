#ifndef GENERATE_H
#define GENERATE_H

#include<string>

extern int file_linked_list_counter;
extern int file_int_counter;

struct Node {
    int value;
    Node* pNext;
};

void pushBack(Node*& pHead ,int pValue);

Node* generateRandomList(int n);
int* generateRandomIntList(int n);

void writeIntListToFile(int* data, int n, std::string filename);
void writeLinkedListToFile(Node* pHead, int n, std::string filename);

void printList(Node* pHead);

std::string createFilename(std::string rootFolderPath, std::string genMode);

#endif