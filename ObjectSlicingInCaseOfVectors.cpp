// ObjectSlicingInCaseOfVectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string_view>
#include <vector>
#include <functional>
class Base
{
    int m_value{};

public:
    Base(int value) : m_value{ value }
    {}
    virtual std::string_view getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived : public Base
{
public:
    Derived(int value) : Base{ value }
    {}
    std::string_view getName() const override { return "Derived"; }
};

int main()
{
    std::vector<Base> v{};

    Derived d{ 5 };
    Base b{ 6 };

    v.push_back(d);
    v.push_back(b);
    v.push_back(Derived{ 7 });
    v.push_back(Base{ 8 });

    // Print out all of the elements in our vector
    for (const auto& element : v)
        std::cout << "I am a " << element.getName() << " with value " << element.getValue() << '\n';

    std::vector<Base*> v1{};
    v1.push_back(&d);
    v1.push_back(&b);

    for (const auto* element : v1)
        std::cout << "I am a " << element->getName() << " with value " << element->getValue() << '\n';

    std::vector<std::reference_wrapper<Base>> v2{};
    v2.push_back(d);
    v2.push_back(b);

    for (const auto& element : v2)
        std::cout << "I am a " << element.get().getName() << " with value " << element.get().getValue() << '\n';

    return 0;
}
