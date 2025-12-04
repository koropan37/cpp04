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

	//const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	//meta->makeSound();
	//delete meta;
	delete i;
	delete j;
	std::cout << std::endl;

	printColor("CORRECT", GREEN);
	Animal* animals[6];
	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0)
		animals[i] = new Cat();
		else
		animals[i] = new Dog();
	}
	animals[0]->makeSound();
	animals[1]->makeSound();
	for (int i = 0; i < 6; i++) {
		delete animals[i];
	}

	std::cout << std::endl;

	printColor("DEEP COPY", MAGENTA);
	Cat a;
	std::cout << std::endl;

	a.addIdea("Idea of a 1");
	a.addIdea("Idea of a 2");
	a.addIdea("Idea of a 3");
	a.printIdeas();
	std::cout << "This is now a brain" << std::endl;
	std::cout << std::endl;

	std::cout << "Copy brain from a to b" << std::endl;
	{
		Cat b(a);
		std::cout << std::endl;

		b.printIdeas();
		std::cout << "This is now b brain" << std::endl;
		std::cout << std::endl;
		b.addIdea("Idea of b 1");
		b.addIdea("Idea of b 2");
		b.addIdea("Idea of b 3");
		b.printIdeas();
		std::cout << "This is now b brain" << std::endl;
		std::cout << std::endl;
	}
	std::cout << "After b is destroyed" << std::endl;
	std::cout << std::endl;

	a.printIdeas();
	std::cout << "This is now b brain" << std::endl;
	std::cout << std::endl;

	std::cout << "Copy operator from a to c" << std::endl;
	{
		Cat c;
		c = a;
		std::cout << std::endl;

		c.printIdeas();
		std::cout << "This is now c brain" << std::endl;
		std::cout << std::endl;
		c.addIdea("Idea of b 1");
		c.addIdea("Idea of b 2");
		c.addIdea("Idea of b 3");
		c.printIdeas();
		std::cout << "This is now c brain" << std::endl;
		std::cout << std::endl;
	}
	std::cout << "After c is destroyed" << std::endl;
	std::cout << std::endl;

	a.printIdeas();
	std::cout << "This is now a brain" << std::endl;
	std::cout << std::endl;


	// printColor("SHALLOW COPY", RED);
	// WrongDog wa;
	// std::cout << std::endl;

	// wa.addIdea("Idea of a 1");
	// wa.addIdea("Idea of a 2");
	// wa.addIdea("Idea of a 3");
	// wa.printIdeas();
	// std::cout << "This is now wa brain" << std::endl;
	// std::cout << std::endl;

	// std::cout << "Copy brain from wa to wb" << std::endl;
	// {
	// 	WrongDog wb(wa);
	// 	std::cout << std::endl;

	// 	wb.printIdeas();
	// 	std::cout << "This is now wb brain" << std::endl;
	// 	std::cout << std::endl;
	// 	wb.addIdea("Idea of b 1");
	// 	wb.addIdea("Idea of b 2");
	// 	wb.addIdea("Idea of b 3");
	// 	wb.printIdeas();
	// 	std::cout << "This is now wb brain" << std::endl;
	// 	std::cout << std::endl;
	// }
	// std::cout << "After wb is destroyed" << std::endl;
	// std::cout << std::endl;

	// wa.printIdeas();
	// std::cout << "This is now wa brain" << std::endl;
	// std::cout << std::endl;

	// std::cout << "Copy operator from wa to wc" << std::endl;
	// {
	// 	WrongDog wc;
	// 	wc = wa;
	// 	std::cout << std::endl;

	// 	wc.printIdeas();
	// 	std::cout << "This is now wb brain" << std::endl;
	// 	std::cout << std::endl;
	// 	wc.addIdea("Idea of b 1");
	// 	wc.addIdea("Idea of b 2");
	// 	wc.addIdea("Idea of b 3");
	// 	wc.printIdeas();
	// 	std::cout << "This is now wc brain" << std::endl;
	// 	std::cout << std::endl;
	// }
	// std::cout << "After wc is destroyed" << std::endl;
	// std::cout << std::endl;

	// wa.printIdeas();
	// std::cout << "This is now wa brain" << std::endl;
	// std::cout << std::endl;
	return 0;
}
