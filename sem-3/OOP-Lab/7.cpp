#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int roll;

public:
    void set_Data(string n, int r)
    {
        name = n;
        roll = r;
    }

    void get_Data()
    {
        cout << "Name: " << name << ", Roll: " << roll << endl;
    }
};

int main()
{
    Student student1, student2;

    student1.set_Data("Alice", 1);
    student2.set_Data("Bob", 2);

    cout << "Student 1: ";
    student1.get_Data();

    cout << "Student 2: ";
    student2.get_Data();

    return 0;
}