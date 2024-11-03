#include <iostream>

class FLOAT
{
private:
    float value;

public:
    // Constructor
    FLOAT(float v = 0.0f) : value(v) {}

    // Overload the + operator
    FLOAT operator+(const FLOAT &other) const
    {
        return FLOAT(this->value + other.value);
    }

    // Overload the - operator
    FLOAT operator-(const FLOAT &other) const
    {
        return FLOAT(this->value - other.value);
    }

    // Overload the * operator
    FLOAT operator*(const FLOAT &other) const
    {
        return FLOAT(this->value * other.value);
    }

    // Overload the / operator
    FLOAT operator/(const FLOAT &other) const
    {
        if (other.value == 0)
        {
            throw std::runtime_error("Division by zero");
        }
        return FLOAT(this->value / other.value);
    }

    // Friend function to overload << operator for easy output
    friend std::ostream &operator<<(std::ostream &os, const FLOAT &f)
    {
        os << f.value;
        return os;
    }
};

int main()
{
    float f1Value, f2Value;

    std::cout << "Enter value for f1: ";
    std::cin >> f1Value;
    FLOAT f1(f1Value);

    std::cout << "Enter value for f2: ";
    std::cin >> f2Value;
    FLOAT f2(f2Value);

    FLOAT f3 = f1 + f2;
    FLOAT f4 = f1 - f2;
    FLOAT f5 = f1 * f2;
    FLOAT f6 = f1 / f2;

    std::cout << "f1 + f2 = " << f3 << std::endl;
    std::cout << "f1 - f2 = " << f4 << std::endl;
    std::cout << "f1 * f2 = " << f5 << std::endl;
    std::cout << "f1 / f2 = " << f6 << std::endl;

    return 0;
}