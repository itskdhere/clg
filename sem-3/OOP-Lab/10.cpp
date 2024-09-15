#include <iostream>

class ClassB; // Forward declaration

class ClassA
{
private:
    int valueA;

public:
    ClassA(int val) : valueA(val) {}
    friend int addMembers(const ClassA &a, const ClassB &b);
};

class ClassB
{
private:
    int valueB;

public:
    ClassB(int val) : valueB(val) {}
    friend int addMembers(const ClassA &a, const ClassB &b);
};

int addMembers(const ClassA &a, const ClassB &b)
{
    return a.valueA + b.valueB;
}

int main()
{
    ClassA objA(10);
    ClassB objB(20);
    std::cout << "Sum of members: " << addMembers(objA, objB) << std::endl;
    return 0;
}