// OverrideSpecifier.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string_view>

class A
{
public:
    virtual std::string_view getName1(int x) const { return "A"; }
    virtual std::string_view getName2(int x) const { return "A"; }
    virtual std::string_view getName3(int x) const { return "A"; }
};

class B : public A
{
public:
    // std::string_view getName1(short int x) const override{ return "A"; } // compile error, function is not an override
    // std::string_view getName2(int x) override { return "A"; } // compile error, function is not an override
     std::string_view getName3(int x) const override { return "A"; } // okay, function is an override of A::getName3(int)
};

int main()
{
    return 0;
}

