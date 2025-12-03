#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("?") {
	std::cout << "WrongAnimal Default constructor called " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << "WrongAnimal Copy constructor called " << type << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) {
	std::cout << "WrongAnimal type constructor called " << type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if(this !=  &other) type = other.type;
	std::cout << "WrongAnimal Copy assignment called " << type << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "繝弱う繧ｺ縺ｿ縺溘" << std::endl;
}

std::string WrongAnimal::getType() const { return type; }
