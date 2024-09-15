#include <iostream>
using namespace std;

int main()
{
    int num, sumOfDigits = 0, remainder;

    // Input the number from the user
    cout << "Enter a positive integer: ";
    cin >> num;

    // Calculate the sum of individual digits
    while (num > 0)
    {
        remainder = num % 10;
        sumOfDigits += remainder;
        num /= 10;
    }

    // Output the sum of the digits
    cout << "Sum of the digits: " << sumOfDigits << endl;

    return 0;
}