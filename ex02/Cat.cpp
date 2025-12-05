#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), brain_(new Brain()) {
	std::cout << "Cat Default constructor called " << type << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain_(new Brain(*other.brain_)) {
	std::cout << "Cat Copy constructor called " << type << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if(this !=  &other) {
		Animal::operator=(other);
    	delete brain_;
    	brain_ = new Brain(*other.brain_);
	}
	std::cout << "Cat Copy assignment called " << type << std::endl;
	return *this;
}
//shallow copy（同じメモリ領域を指している)
//... コピー元のデータに変更を加えるとコピー先も変更される

//deep    copy (違うメモリ両機を指してる)
//... コピー元のデータに変更を加えてもコピー先は変更されない

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
	delete brain_;
}

void Cat::makeSound() const {
	std::cout << "meow!" << std::endl;
}

void Cat::printIdeas() const {
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

void Cat::addIdea(const std::string& idea) { brain_->addIdeas(idea); }
