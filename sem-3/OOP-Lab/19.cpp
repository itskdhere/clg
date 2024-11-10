#include <iostream>
using namespace std;

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    void displayDimensions() const
    {
        std::cout << "Length: " << length << ", Width: " << width << std::endl;
    }

    friend class AreaCalculator;
};

class AreaCalculator
{
public:
    double calculateArea(const Rectangle &rect) const
    {
        return rect.length * rect.width;
    }
};

int main()
{
    double l, w;
    cout << "Enter the length of the rectangle: ";
    cin >> l;
    cout << "Enter the width of the rectangle: ";
    cin >> w;
    Rectangle rect(l, w);

    AreaCalculator calculator;

    rect.displayDimensions();
    double area = calculator.calculateArea(rect);
    std::cout << "Area: " << area << std::endl;

    return 0;
}