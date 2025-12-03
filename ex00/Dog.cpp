#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog Default constructor called " << type << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog Copy constructor called " << type << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if(this !=  &other) Animal::operator=(other);
	std::cout << "Dog Copy assignment called " << type << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "vow!" << std::endl;
}
