#include "WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog() : WrongAnimal("WrongDog"), brain_(new Brain()) {
	std::cout << "WrongDog Default constructor called " << type << std::endl;
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other) {
    brain_ = other.brain_;
    std::cout << "WrongDog Copy constructor called (shallow)" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& other) {
    if(this !=  &other) {
        WrongAnimal::operator=(other);
        brain_ = other.brain_;
    }
    std::cout << "WrongDog Copy assignment called (shallow)" << std::endl;
    return *this;
}

WrongDog::~WrongDog() {
	std::cout << "WrongDog Destructor called" << std::endl;
	//delete brain_;
}
//もし delete を入れると複数のオブジェクトが同じ brain_ ポインタを持つため、
//スコープの終了ごとに delete が呼ばれ、クラッシュや未定義になる

void WrongDog::makeSound() const {
	std::cout << "vow!" << std::endl;
}

void WrongDog::printIdeas() const {
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

void WrongDog::addIdea(const std::string& idea) { brain_->addIdeas(idea); }
