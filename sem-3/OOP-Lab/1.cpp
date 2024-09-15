#include <iostream>
using namespace std;

int main()
{
    int num, originalNum, reversedNum = 0, remainder;

    // Input the number from the user
    cout << "Enter an integer: ";
    cin >> num;

    originalNum = num;

    // Reverse the number
    while (num != 0)
    {
        remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    // Check if the original number is equal to the reversed number
    if (originalNum == reversedNum)
    {
        cout << originalNum << " is a palindrome." << endl;
    }
    else
    {
        cout << originalNum << " is not a palindrome." << endl;
    }

    return 0;
}