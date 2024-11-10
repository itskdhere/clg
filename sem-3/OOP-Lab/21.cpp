#include <iostream>
#include <string>

class Student
{
public:
    virtual double calculateGrade() = 0; // Pure virtual function
    virtual std::string getMajor() = 0;  // Pure virtual function
};

class EngineeringStudent : public Student
{
private:
    double examScore;
    double projectScore;

public:
    EngineeringStudent(double exam, double project) : examScore(exam), projectScore(project) {}

    double calculateGrade() override
    {
        return (examScore * 0.7) + (projectScore * 0.3);
    }

    std::string getMajor() override
    {
        return "Engineering";
    }
};

class ArtStudent : public Student
{
private:
    double assignmentScore;
    double finalProjectScore;

public:
    ArtStudent(double assignment, double finalProject) : assignmentScore(assignment), finalProjectScore(finalProject) {}

    double calculateGrade() override
    {
        return (assignmentScore * 0.4) + (finalProjectScore * 0.6);
    }

    std::string getMajor() override
    {
        return "Art";
    }
};

int main()
{
    EngineeringStudent engStudent(85.0, 90.0);
    ArtStudent artStudent(80.0, 95.0);

    std::cout << "Major: " << engStudent.getMajor() << ", Grade: " << engStudent.calculateGrade() << std::endl;
    std::cout << "Major: " << artStudent.getMajor() << ", Grade: " << artStudent.calculateGrade() << std::endl;

    return 0;
}