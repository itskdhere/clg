#include <iostream>
using namespace std;

// Base class
class Shape
{
protected:
    double width;
    double height;

public:
    void setWidth(double w)
    {
        width = w;
    }

    void setHeight(double h)
    {
        height = h;
    }
};

// Derived class
class Rectangle : public Shape
{
public:
    double getArea()
    {
        return width * height;
    }
};

int main()
{
    double w, h;
    Rectangle rect;

    cout << "Enter the width of the rectangle: ";
    cin >> w;
    rect.setWidth(w);

    cout << "Enter the height of the rectangle: ";
    cin >> h;
    rect.setHeight(h);

    double area = rect.getArea();

    cout << "Area of the rectangle: " << area << endl;

    return 0;
}