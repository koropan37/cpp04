#include "WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog() : WrongAnimal("WrongDog") {
	std::cout << "WrongDog Default constructor called " << type << std::endl;
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other) {
	std::cout << "WrongDog Copy constructor called " << type << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& other) {
	if(this !=  &other) WrongAnimal::operator=(other);
	std::cout << "WrongDog Copy assignment called " << type << std::endl;
	return *this;
}

WrongDog::~WrongDog() {
	std::cout << "WrongDog Destructor called" << std::endl;
}

void WrongDog::makeSound() const {
	std::cout << "vow!" << std::endl;
}
