#include "generate.h"

#include <iostream>
#include <cmath>

/*
Argument typedef:
argv[0]: ./a

*/

int main(int argc, char *argv[])
{
    Node* myList; // create empty list

    if (argc < 3)
    {
        std::cout << "Wrong command-line arguments. Please check again" << std::endl;
        return 0;
    }
    else if (argc == 3)
    {
        if (std::string(argv[0]) != "./a")
        {
            std::cout << "Wrong execute filename " << argv[0] << std::endl;
            std::cout << "Build again with: \n" << "g++ main.cpp generate.cpp -o a" << std::endl;
            return 0;
        }
        else
        {
            if (std::string(argv[1]) == "test_generate")
            {
                int n; // number of elements in command-line
                try
                {
                    n = std::stoi(std::string(argv[2])); // check whether argument valid or not
                    myList = generateRandomList(n);
                    throw(argv[2]);
                }
                catch (const char* c)
                {
                    std::cout << "Can not convert " <<  c << " to int." << std::endl;
                }
                catch(const std::out_of_range *r)
                {
                    std::cout << "Value " <<  r << " is out of range." << std::endl;
                }

                printList(myList); // print to check
            }
            else 
            {
                std::cout << "Function will be invent later" << std::endl;
            }
        }
    }
    else if (argc > 3)
    {
        std::cout << "Function will be invent later" << std::endl;
    }

    return 0;
}