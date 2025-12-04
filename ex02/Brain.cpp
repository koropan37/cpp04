#include "Brain.hpp"
#include <iostream>

Brain::Brain() :ideas(), i_(0) {
	std::cout << "Brain Default constructor called " << std::endl;
}

Brain::Brain(const Brain& other) : i_(other.i_) {
    std::cout << "Brain Copy constructor called "<< std::endl;
    for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
	if(this !=  &other) {
		for(int i = 0; i < 100; ++i)
			ideas[i] = other.ideas[i];
	}
	i_ = other.i_;
	std::cout << "Brain Copy assignment called " << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl;
}

std::string Brain::getIdeas(int i) const {
	if(i < 0 || i >= 100) return "no idea";
	return ideas[i];
}

void Brain::addIdeas(const std::string& idea) {
	if(i_ < 0 || i_ >= 100) return ;

	this->ideas[i_] = idea;
	i_++;
}
