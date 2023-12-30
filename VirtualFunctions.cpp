// VirtualFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string_view>

class A
{
public:
    virtual std::string_view getName() { return "A"; }
};
class B : public A
{
public:
    virtual std::string_view getName() { return "B"; }
};
class C : public B
{
public:
    virtual std::string_view getName() { return "C"; }
};
class D : public C
{
public:
    virtual std::string_view getName() { return "D"; }
};

int main()
{
    C c{};
    A& rBase{ c };
    std::cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
}

