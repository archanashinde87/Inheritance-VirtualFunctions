// VirtualDestructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Base
{
public:
	virtual ~Base()
	{
		std::cout << "Calling ~Base()\n";
	}

};

class Derived : public Base
{
	int* m_array{};

public:
	Derived(int length)
		:m_array{ new int[length] }
	{}
	virtual ~Derived()
	{
		std::cout << "Calling ~Derived()\n";
		delete[] m_array;
	}

};
int main()
{
	Derived* derived{new Derived(5) };
	Base* base{ derived };

	delete base;

	return 0;
}

