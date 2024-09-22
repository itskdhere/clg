#include <iostream>
#define MAX 3
using namespace std;

class Student
{
private:
    string sname;
    int marks[MAX];
    int total = 0;
    int tmax;

public:
    void assign()
    {
        cout << "Enter Name: ";
        cin >> sname;
        for (int i = 0; i < MAX; i++)
        {
            cout << "Enter Marks In Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }
    void compute()
    {
        for (int i = 0; i < MAX; i++)
        {
            total += marks[i];
        }
        tmax = total / MAX;
    }
    void display()
    {
        cout << "\nName: " << sname;
        cout << "\nMarks: ";
        for (int i = 0; i < MAX; i++)
        {
            cout << marks[i] << " ";
        }
        cout << "\nTotal: " << total;
        cout << "\nAverage: " << tmax;
    }
};

int main()
{
    Student s;
    s.assign();
    s.compute();
    s.display();
    return 0;
}