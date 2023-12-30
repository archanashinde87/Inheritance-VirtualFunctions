// DynamicCasting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string_view>
#include <string>

class Base
{
protected:
	int m_value{};
public:
	Base(int value)
		:m_value{ value }
	{}

	virtual ~Base() = default;
};

class Derived : public Base
{
protected:
	std::string m_name{};
public:
	Derived(int value, std::string_view name)
		: Base{ value }, m_name{ name }
	{}
	const std::string& getName() const { return m_name; }
};
Base* getObject(bool returnDerived)
{
	if (returnDerived)
		return new Derived{ 1,"Apple" };
	else
		return new Base{ 2 };
}
int main()
{
	Base* b{ getObject(true) };

	// how do we print the Derived object's name here, having only a Base pointer?
	Derived* d{ dynamic_cast<Derived*>(b) }; // use dynamic cast to convert Base pointer into Derived pointer

	if(d) // make sure d is non-null
	std::cout << "The name of the derived is : " << d->getName() << '\n';

	delete b;

	return 0;
}

