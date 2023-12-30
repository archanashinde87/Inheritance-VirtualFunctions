// MultipleInheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view>

class Person
{
    std::string m_name{};
    int m_age{};

public:
    Person(std::string_view name, int age)
        :m_name{ name }, m_age{age}
    {}
    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
};
class Employee
{
    std::string m_employer{};
    double m_wage{};

public:
    Employee(std::string_view employer, double wage)
        :m_employer{ employer }, m_wage{ wage }
    {}
    const std::string& getEmployer() const { return m_employer; }
    double getWage() const { return m_wage; }

};

// Teacher publicly inherits Person and Employee
class Teacher : public Person, public Employee
{
    int m_teachesGrade{};

public:
    Teacher(std::string_view name, int age, std::string_view employer, double wage, int teachesGrade)
        : Person(name,age)
        , Employee(employer, wage)
        , m_teachesGrade{teachesGrade}
    {}
    int getGrade() const { return m_teachesGrade; }
};

int main()
{
    Teacher t{ "Archana", 30, "Pune University", 34.5, 8 };

    std::cout << "Name: " << t.getName() << '\n';
    std::cout << "Age: " << t.getAge() << '\n';
    std::cout << "Employer: " << t.getEmployer() << '\n';
    std::cout << "Wage: " << t.getWage() << '\n';
    std::cout << "Grade: " << t.getGrade() << '\n';

    return 0;
}

