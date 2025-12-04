#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), brain_(new Brain()){
	std::cout << "Dog Default constructor called " << type << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog Copy constructor called " << type << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if(this !=  &other) {
		Animal::operator=(other);
		*brain_ = *other.brain_;
	}
	std::cout << "Dog Copy assignment called " << type << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
	delete brain_;
}

void Dog::makeSound() const {
	std::cout << "vow!" << std::endl;
}

void Dog::printIdeas() const {
    for (int i = 0; i < 100; ++i) {
        std::string s = brain_->getIdeas(i);
        if (s == "no idea") {
            std::cerr << i << s << std::endl;
			return ;
		}
		else if (s != "")
			std::cout << i << ": " << s << std::endl;
	}
}

void Dog::addIdea(const std::string& idea) { brain_->addIdeas(idea); }
