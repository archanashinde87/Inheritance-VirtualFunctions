// VirtualFunctions2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view>

class Animal 
{
protected:
	std::string m_name{};
	Animal(std::string_view name)
		:m_name{ name }
	{}

public:
	const std::string& getName() const { return m_name; }
	virtual std::string_view speak() const { return "???"; }
};

class Cat : public Animal
{
public:
	Cat(std::string_view name)
		:Animal{ name }
	{}

	virtual std::string_view speak() const { return "Meow"; }
};

class Dog : public Animal
{
public:
	Dog(std::string_view name)
		:Animal{ name }
	{}

	virtual std::string_view speak() const { return "Woof"; }
};

void report(const Animal& animal)
{
	std::cout << animal.getName() << " says " << animal.speak() << '\n';
}
int main()
{
	Cat cat{ "Fred" };
	Dog dog{ "Garbo" };

	report(cat);
	report(dog);

	// array example now works 
	Cat fred{ "Fred" };
	Cat misty{ "Misty" };
	Cat zeke{ "Zeke" };

	Dog garbo{ "Garbo" };
	Dog pooky{ "Pooky" };
	Dog truffle{ "Truffle" };

	Animal* animals[]{ &fred,&misty,&zeke,&garbo,&pooky,&truffle };

	for (const auto* animal : animals)
		std::cout << animal->getName() << " says " << animal->speak() << '\n';

	return 0;
}

