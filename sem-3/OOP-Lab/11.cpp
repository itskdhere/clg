#include <iostream>
#include <cmath>

class Polar
{
private:
    double radius;
    double angle; // in radians

public:
    // Constructor
    Polar(double r = 0, double a = 0) : radius(r), angle(a) {}

    // Getter methods
    double getRadius() const { return radius; }
    double getAngle() const { return angle; }

    // Overload + operator to add two Polar objects
    Polar operator+(const Polar &p) const
    {
        // Convert polar to Cartesian coordinates
        double x1 = radius * cos(angle);
        double y1 = radius * sin(angle);
        double x2 = p.radius * cos(p.angle);
        double y2 = p.radius * sin(p.angle);

        // Add Cartesian coordinates
        double x = x1 + x2;
        double y = y1 + y2;

        // Convert back to polar coordinates
        double r = sqrt(x * x + y * y);
        double a = atan2(y, x);

        return Polar(r, a);
    }

    // Display method
    void display() const
    {
        std::cout << "Radius: " << radius << ", Angle: " << angle << " radians" << std::endl;
    }
};

int main()
{
    double r, a;

    std::cout << "Enter radius and angle (in radians) for Polar 1: ";
    std::cin >> r >> a;
    Polar p1(r, a);

    std::cout << "Enter radius and angle (in radians) for Polar 2: ";
    std::cin >> r >> a;
    Polar p2(r, a);

    Polar p3 = p1 + p2;

    std::cout << "\nP1: ";
    p1.display();
    std::cout << "P2: ";
    p2.display();
    std::cout << "P3 (P1 + P2): ";

    p3.display();

    return 0;
}