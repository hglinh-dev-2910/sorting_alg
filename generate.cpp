#include "generate.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include<fstream>
#include<sstream>

int file_linked_list_counter = 0;
int file_int_counter = 0;


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

int *generateRandomIntList(int n)
{   
    int* intList = new int[n];
    srand(time(0));

    for(int i = 0; i < n; i++) {
        intList[i] = rand()% n;
    }
    
    return intList;
}

void writeIntListToFile(int* data, int n, std::string filename)
{
    //int* tmpData = generateRandomIntList(n);

    std::ofstream outfile(filename);
    if(!outfile) {
        std::cout << filename << " had not been created." << std::endl;
        return;
    }
    else 
    {
        outfile << n << std::endl; // first line
        for (int i = 0; i < n; i++)
        {
            outfile << data[i] << std::endl; // write each value in 1 line (2 -> n + 1)
        }
        outfile.close(); // close file after write
 
        std::cout << "Writed " << n << " values to " << filename << std::endl;
        
    }
}

void writeLinkedListToFile(Node *pHead, int n, std::string filename)
{
    std::ofstream outFile(filename); //assume file created 

    outFile << n << std::endl;

    Node* currentNode = pHead;
    while (currentNode != nullptr)
    {
        outFile << currentNode->value << std::endl;
        currentNode = currentNode->pNext;
    }

    outFile.close();

    std::cout << "Writed " << n << " values to " << filename << std::endl;
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


std::string createFilename(std::string rootFolderPath, std::string genMode)
{
    std::ostringstream filenameBuilder; // create file name
    filenameBuilder << rootFolderPath;
    if (genMode == "int")
    {
        filenameBuilder << "/intListRandomGenerate_";
        std::string orderedName = std::to_string(file_int_counter);
        filenameBuilder << orderedName << ".txt";
    } 
    else if (genMode == "linked_list") 
    {
        filenameBuilder << "/linkedListRandomGenerate_";
        std::string orderedName = std::to_string(file_linked_list_counter);
        filenameBuilder << orderedName << ".txt";
    } 
    else 
    {
        return "Wrong genMode";
    }
    
    
    std::string filename = filenameBuilder.str();

    return filename;
}