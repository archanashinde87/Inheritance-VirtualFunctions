// PureVirtualFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string_view>

class Base
{
public:
	std::string_view sayhi() const { return "hi"; } // a normal non-virtual function
	virtual std::string_view getName() const { return "Base"; } // a normal virtual function
	virtual int	getValue() = 0; // a pure virtual function
	//int doSomething() = 0; // compile error : cannot set non virtual function to 0
};

int main()
{
	return 0;
}
