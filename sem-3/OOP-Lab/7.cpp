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
        cout << "Name: " << name << "\nRoll: " << roll << endl;
    }
};

int main()
{
    Student student1, student2;
    string name1, name2;
    int roll1, roll2;
    cout << "Student 1 Name: ";
    cin >> name1;
    cout << "Student 1 Roll: ";
    cin >> roll1;
    cout << "Student 2 Name: ";
    cin >> name2;
    cout << "Student 2 Roll: ";
    cin >> roll2;

    student1.set_Data(name1, roll1);
    student2.set_Data(name2, roll2);

    cout << "\nStudent 1: \n";
    student1.get_Data();

    cout << "\nStudent 2: \n";
    student2.get_Data();

    return 0;
}