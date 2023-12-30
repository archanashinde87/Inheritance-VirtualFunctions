// BasicInheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string_view>
#include <string>

class Person
{
public:
    std::string m_name{};
    int m_age{};

    Person(std::string_view name="", int age=0)
        :m_name{ name }, m_age{age}
    {}
    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
};

// BaseBallPerson publically inheritting Person
class BaseBallPlayer : public Person
{
public:
   double m_battingAverage{};
   int m_homeRuns{};

   BaseBallPlayer(double battingAverage = 0.0, int homeRuns = 0)
       :m_battingAverage{ battingAverage }, m_homeRuns{ homeRuns }
   {}
};

class Employee : public Person
{
public:
    double m_hourlySalary{};
    long m_employeeID{};

    Employee(double hourlySalary=0.0, int employeeID=0)
        :m_hourlySalary{ hourlySalary }, m_employeeID{employeeID}
    {}
    void printNameAndSalary()
    {
        std::cout << m_name << " has hourly wage rate of " << m_hourlySalary << '\n';
    }
};
int main()
{
    BaseBallPlayer arch{};
    // Assign it a name (we can do this directly because m_name is public)
    arch.m_name = "Archana";
    // print out the name
    std::cout << arch.getName() << '\n';

    Employee shanky{ 20.43, 12345 };
    shanky.m_name = "Shankar";
    shanky.printNameAndSalary();

    return 0;
}

