// ObjectSlicing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string_view>

class Base
{
protected:
    int m_value{};
public:
    Base(int value) :m_value{ value }
    {}
    virtual ~Base() = default;
    virtual std::string_view getName() const { return "Base"; }
    int getValue() { return m_value; }
};

class Derived : public Base
{
public:
    Derived(int value) :Base{ value }
    {}
    std::string_view getName() const override { return "Derived"; }

};

void printName1(const Base base) // note : base passed by value and not reference
{
    std::cout << "I am a " << base.getName() << '\n';
}
void printName2(const Base& base) // note : base passed by reference
{
    std::cout << "I am a " << base.getName() << '\n';
}

int main()
{
    Derived derived{ 5 };
    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

    Base& ref{ derived };
    std::cout << "ref is a " << ref.getName() << " and has value " << ref.getValue() << '\n';

    Base* ptr{ &derived };
    std::cout << "ptr is a " << ptr->getName() << " and has value " << ptr->getValue() << '\n';

    Base base{ derived }; // the assigning of a Derived class object to a Base class object is called object slicing
    std::cout << "base is a " << base.getName() << " and has value " << base.getValue() << '\n';

    printName1(derived); // oops, didn't realize this was pass by value on the calling end
    printName2(derived); // it works as expected as this was pass by reference on the calling end

    return 0;
}

