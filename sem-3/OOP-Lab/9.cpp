#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Getter and Setter for real part
    double getReal() const { return real; }
    void setReal(double r) { real = r; }

    // Getter and Setter for imaginary part
    double getImag() const { return imag; }
    void setImag(double i) { imag = i; }

    // Overload + operator
    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex &other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    // Display function
    void display() const
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    // Create 3 objects of Complex class
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3;

    // Add c1 and c2
    c3 = c1 + c2;
    cout << "c1 + c2 = ";
    c3.display();

    // Subtract c2 from c1
    c3 = c1 - c2;
    cout << "c1 - c2 = ";
    c3.display();

    return 0;
}