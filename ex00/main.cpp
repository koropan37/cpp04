#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include <iostream>

#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"
#define RESET   "\033[0m"
#define B_RED	"\033[1;31m"
#define B_GREEN "\033[1;32m"
#define B_CYAN  "\033[1;36m"

void printColor(std::string const& str, std::string const& color) {
    std::cout
	<< RESET << "======="
	<< color << str
	<< RESET << "=======" << color << std::endl;
}

int main()
{
	printColor("SUBJECT", CYAN);
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	std::cout << std::endl;

	printColor("CORRECT", GREEN);
	Animal *animals[3];
	animals[0] = new Animal("Cute");
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[0]->makeSound();
	animals[1]->makeSound();
	animals[2]->makeSound();
	delete animals[0];
	delete animals[1];
	delete animals[2];
	std::cout << std::endl;

	{
		Cat c;
		Cat c2;
		c = c2;
		Dog d;
		Dog d2;
		d = d2;
		Animal& a = c;
		Animal& a2(d);
		c.makeSound();
		d.makeSound();
		a.makeSound();
		a2.makeSound();
	}
	std::cout << std::endl;

	printColor("WRONG", RED);
	WrongAnimal *wrong_animals[3];
	wrong_animals[0] = new WrongAnimal("Alien");
	wrong_animals[1] = new WrongCat();
	wrong_animals[2] = new WrongDog();
	wrong_animals[0]->makeSound();
	wrong_animals[1]->makeSound();
	wrong_animals[2]->makeSound();
	delete wrong_animals[0];
	delete wrong_animals[1];
	delete wrong_animals[2];
	std::cout << std::endl;

	{
		WrongCat wc;
		WrongCat wc2;
		wc2 = wc;
		WrongDog wd;
		WrongDog wd2;
		wd2 = wd;
		WrongAnimal& wa = wc;
		WrongAnimal& wa2(wd);
		wc.makeSound();
		wd.makeSound();
		wa.makeSound();
		wa2.makeSound();
	}
	std::cout << std::endl;

return 0;
}
