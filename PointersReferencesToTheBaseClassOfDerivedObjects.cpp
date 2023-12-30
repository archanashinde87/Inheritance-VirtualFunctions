// PointersReferencesToTheBaseClassOfDerivedObjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string_view>

class Base 
{
protected :
    int m_value{};

public:
    Base(int value)
        :m_value{ value }
    {}

    std::string_view getName() const { return "Base"; }
    int getValue() const { return m_value; }
};
class Derived : public Base
{
public:
    Derived(int value)
        : Base{ value }
    {}
    std::string_view getName() const { return "Derived"; }
    int getDoubleValued() { return m_value * 2; }
};

int main()
{
    Derived derived{ 5 };
    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

    Derived& rDerived{ derived };
    std::cout << "rDerived is a " << rDerived.getName() << " and has value " << rDerived.getValue() << '\n';

    Derived* pDerived{ &derived };
    std::cout << "pDerived is a " << pDerived->getName() << " and has value " << pDerived->getValue() << '\n';

    Base& rBase{ derived };
    std::cout << "rBase is a " << rBase.getName() << " and has value " << rBase.getValue() << '\n';

    Base* pBase{&derived};
    std::cout << "pBase is a " << pBase->getName() << " and has value " << pBase->getValue() << '\n';

    return 0;
}

