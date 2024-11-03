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
    double r, i;

    cout << "Enter the real part of the first complex number: ";
    cin >> r;
    cout << "Enter the imaginary part of the first complex number: ";
    cin >> i;
    Complex c1(r, i);

    cout << "Enter the real part of the second complex number: ";
    cin >> r;
    cout << "Enter the imaginary part of the second complex number: ";
    cin >> i;
    Complex c2(r, i);

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