#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat"), brain_(new Brain()) {
	std::cout << "WrongCat Default constructor called " << type << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    brain_ = other.brain_;
    std::cout << "WrongCat Copy constructor called (shallow)" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if(this !=  &other) {
        WrongAnimal::operator=(other);
        brain_ = other.brain_;
    }
    std::cout << "WrongCat Copy assignment called (shallow)" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
	//delete brain_;
}

void WrongCat::makeSound() const {
	std::cout << "meow!" << std::endl;
}

void WrongCat::printIdeas() const {
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

void WrongCat::addIdea(const std::string& idea) { brain_->addIdeas(idea); }
