// FinalSpecifier.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string_view>

class A
{
public:
	virtual std::string_view getName() const { return "A"; }
};
class B : public A
{
public:
	// note use of final specifier on following line -- that makes this function not able to be overridden in derived classes
	std::string_view getName() const override final { return "B"; } // okay, overrides A::getName()
};

class C : public B
{
public:
	//std::string_view getName() const override{ return "C"; } // compile error: overrides B::getName(), which is final
};

class X
{
public:
	virtual std::string_view getName() const { return "X"; }
};

class Y final : public X // note use of final specifier here
{
public:
	std::string_view getName() const override { return "Y"; }
};

//class Z : public Y // compile error: cannot inherit from final class
//{
//public:
//	std::string_view getName() const override { return "Z"; }
//};

int main()
{
	return 0;
}

