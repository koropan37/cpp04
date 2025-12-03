#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), brain_(new Brain()) {
	std::cout << "Cat Default constructor called " << type << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain_(new Brain(*other.brain_)) {
	std::cout << "Cat Copy constructor called " << type << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if(this !=  &other) Animal::operator=(other);
	std::cout << "Cat Copy assignment called " << type << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "meow!" << std::endl;
}
