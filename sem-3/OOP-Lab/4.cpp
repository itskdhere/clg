#include <iostream>

int main()
{
    int n;
    std::cout << "Enter the number of integers: ";
    std::cin >> n;

    if (n <= 0)
    {
        std::cout << "Please enter a positive number of integers." << std::endl;
        return 1;
    }

    int number;
    std::cout << "Enter integer 1: ";
    std::cin >> number;

    int largest = number;
    int smallest = number;

    for (int i = 1; i < n; ++i)
    {
        std::cout << "Enter integer " << (i + 1) << ": ";
        std::cin >> number;

        if (number > largest)
        {
            largest = number;
        }
        if (number < smallest)
        {
            smallest = number;
        }
    }

    std::cout << "Largest number: " << largest << std::endl;
    std::cout << "Smallest number: " << smallest << std::endl;

    return 0;
}