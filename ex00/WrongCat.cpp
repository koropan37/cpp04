#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat Default constructor called " << type << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat Copy constructor called " << type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if(this !=  &other) WrongAnimal::operator=(other);
	std::cout << "WrongCat Copy assignment called " << type << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "meow!" << std::endl;
}
