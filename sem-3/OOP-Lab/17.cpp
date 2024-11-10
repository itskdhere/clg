#include <iostream>
#include <string>
using namespace std;

class Sum
{
public:
    void sum(int a, int b)
    {
        double d = a + b;
        cout << "Sum of integers: " << d << endl;
    }

    void sum(float a, float b)
    {
        float d = a + b;
        cout << "Sum of floats: " << d << endl;
    }

    void sum(string a, string b)
    {
        cout << "Final string: " << a << b << endl;
    }
};

int main()
{
    Sum s;

    int int1, int2;
    cout << "Enter two integers: ";
    cin >> int1 >> int2;
    s.sum(int1, int2);
    cout << endl;

    float float1, float2;
    cout << "Enter two floats: ";
    cin >> float1 >> float2;
    s.sum(float1, float2);
    cout << endl;

    string str1, str2;
    cout << "Enter two strings: ";
    cin >> str1 >> str2;
    s.sum(str1, str2);
    cout << endl;

    return 0;
}