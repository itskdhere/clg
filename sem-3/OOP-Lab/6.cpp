#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    long long first = 0, second = 1, next;

    cout << "Fibonacci sequence: " << first;
    if (n > 1)
    {
        cout << ", " << second;
    }

    for (int i = 3; i <= n; ++i)
    {
        next = first + second;
        cout << ", " << next;
        first = second;
        second = next;
    }

    std::cout << std::endl;
    return 0;
}