#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("") {
	std::cout << "Animal Default constructor called " << type << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Animal Copy constructor called " << type << std::endl;
}

Animal::Animal(const std::string& type) : type(type) {
	std::cout << "Animal type constructor called " << type << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if(this !=  &other) type = other.type;
	std::cout << "Animal Copy assignment called " << type << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "繝弱う繧ｺ縺ｿ縺溘" << std::endl;
}

std::string Animal::getType() const { return type; }
