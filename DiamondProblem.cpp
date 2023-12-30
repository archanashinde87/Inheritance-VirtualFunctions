// DiamondProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class PoweredDevice
{
public:
	PoweredDevice(int power)
	{
		std::cout << "PoweredDevice: " << power << '\n';
	}
};
class Scanner : public PoweredDevice // note : PoweredDevice is a base class
{
public:
	Scanner(int scanner, int power)
		:PoweredDevice(power) // this line is required to create Scanner objects
	{
		std::cout << "Scanner: " << scanner << '\n';
	}
};
class Printer : public PoweredDevice //  note : PoweredDevice is a base class
{
public:
	Printer(int printer, int power)
		:PoweredDevice(power) // this line is required to create Printer objects
	{
		std::cout << "Printer: " << printer << '\n';
	}
};
class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power)
		: Scanner(scanner, power), Printer(printer, power)
	{

	}
};

int main()
{
	Copier copier{ 1,2,3 };
	return 0;
}


