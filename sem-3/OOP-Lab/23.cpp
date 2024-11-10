#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Writing data to the file
    std::ofstream outFile("people.txt");
    if (outFile.is_open())
    {
        outFile << "John Doe, 30\n";
        outFile << "Jane Smith, 25\n";
        outFile << "Alice Johnson, 28\n";
        outFile.close();
    }
    else
    {
        std::cerr << "Unable to open file for writing" << std::endl;
        return 1;
    }

    // Reading data from the file
    std::ifstream inFile("people.txt");
    if (inFile.is_open())
    {
        std::string line;
        while (std::getline(inFile, line))
        {
            std::cout << line << std::endl;
        }
        inFile.close();
    }
    else
    {
        std::cerr << "Unable to open file for reading" << std::endl;
        return 1;
    }

    return 0;
}