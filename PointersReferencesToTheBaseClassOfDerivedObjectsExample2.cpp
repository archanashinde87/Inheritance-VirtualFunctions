// PointersReferencesToTheBaseClassOfDerivedObjectsExample2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view>
#include <array>

class Animal
{
protected:
	std::string m_name{};
	std::string m_speak{};

	// We're making this constructor protected because we don't want people creating Animal objects directly,
	// but we still want derived classes to be able to use it.
	Animal(std::string_view name, std::string_view speak="???")
		: m_name{ name }, m_speak{ speak }
	{}

	// To prevent slicing
	Animal(const Animal& animal) = default;
	Animal& operator=(const Animal& animal) = default;


public:
	const std::string& getName() const { return m_name; }
	const std::string& speak() const { return m_speak; }

};
class Cat : public Animal
{
public:
	Cat(std::string_view name)
		: Animal{ name, "Meow"}
	{}
	//std::string_view speak() const { return "Meow"; }
};
class Dog : public Animal
{
public:
	Dog(std::string_view name)
		: Animal{ name, "Woof"}
	{}
	//std::string_view speak() const { return "Woof"; }
};
int main()
{
	const Cat cat{ "Fred" };
	std::cout << "cat is named " << cat.getName() << ", it says " << cat.speak() << '\n';

	const Dog dog{ "Garbo" };
	std::cout << "dog is named " << dog.getName() << ", it says " << dog.speak() << '\n';

	const Animal* pAnimal{ &cat };
	std::cout << "pAnimal is named " << pAnimal->getName() << ", it says " << pAnimal->speak() << '\n';
	                                         
	pAnimal = &dog ;
	std::cout << "pAnimal is named " << pAnimal->getName() << ", it says " << pAnimal->speak() << '\n';

	const Cat fred{ "Fred" };
	const Cat misty{ "Misty" };
	const Cat zeke{ "Zeke" };

	const Dog garbo{ "Garbo" };
	const Dog pooky{ "Pooky" };
	const Dog truffle{ "Truffle" };

	// Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
	const auto animals{ std::to_array<const Animal*>({ &fred, &garbo, &misty, &pooky, &truffle, &zeke }) };

	// Before C++20, with the array size being explicitly specified
	// const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

	for (const auto animal : animals)
	{
		std::cout << animal->getName() << " says " << animal->speak() << '\n';
	}

	return 0;
}

