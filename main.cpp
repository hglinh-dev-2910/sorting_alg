#include "generate.h"

#include <iostream>
#include <cmath>
#include<fstream>
#include<unordered_map>

const std::unordered_map<std::string, int> algoMap = { //unordered_map to store algo name by index
    {"bubble_sort", 1},
    {"intersection_sort", 2}

};

std::unordered_map<std::string, std::string> loadEnv(const std::string& filename = ".env") {
    std::unordered_map<std::string, std::string> env;
    std::ifstream file(filename);
    std::string line;

    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue; 
        size_t pos = line.find('=');
        if (pos == std::string::npos) continue;
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        env[key] = value;
    }
    return env;
};


int main(int argc, char* argv[])
{
    Node* myList; // create empty list
    int* myIntList;
    auto env = loadEnv();

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
            if (std::string(argv[1]) == "linked_list_generate")
            {
                int n; // number of elements in command-line
                try
                {
                    n = std::stoi(std::string(argv[2])); // check whether argument valid or not
                    

                }
                catch (const char* c)
                {
                    std::cout << "Can not convert " <<  c << " to int." << std::endl;
                }
                catch(const std::out_of_range *r)
                {
                    std::cout << "Value " <<  r << " is out of range." << std::endl;
                }

                myList = generateRandomList(n); 
                std::string filename = createFilename(env["linked_list_gen_root_path"], "linked_list");
                std::cout << filename << std::endl;
                writeLinkedListToFile(myList, n, filename);

                //printList(myList); // print to check
            }
            else if (std::string(argv[1]) == "int_list_generate")
            {
                int n; // number of elements in command-line
                try
                {
                    n = std::stoi(std::string(argv[2])); // check whether argument valid or not
                    
                }
                catch (const char* c)
                {
                    std::cout << "Can not convert " <<  c << " to int." << std::endl;
                }
                catch(const std::out_of_range *r)
                {
                    std::cout << "Value " <<  r << " is out of range." << std::endl;
                }

                myIntList = generateRandomIntList(n); 
                std::string filename = createFilename(env["int_root_path"], "int");
                writeIntListToFile(myIntList, n, filename);
            }
            else 
            {
                std::cout << "Function will be invent later" << std::endl;
            }
        }
    }
    else if (argc == 4)
    {
        /*
            ./a algo 'algo name' 'filename'
        */
        
         if (std::string(argv[0]) != "./a")
        {
            std::cout << "Wrong execute filename " << argv[0] << std::endl;
            std::cout << "Build again with: \n" << "g++ main.cpp generate.cpp -o a" << std::endl;
            return 0;
        }
        else 
        {
            if(std::string(argv[1]) == "algo")
            {
                
                auto algoMapping = algoMap.find(std::string(argv[2]));
                if(algoMapping != algoMap.end()) { //check whether algo name inited or not
                    int algoIndex = algoMapping->second; // stored algo name by index

                    switch (algoIndex)
                    {
                    case 1: // bubble sort
                        
                        break;
                    
                    }
                }
            }
        }

    }

    return 0;
}