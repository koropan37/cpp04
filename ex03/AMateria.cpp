#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() : type_("Normal") {}

AMateria::AMateria(std::string const& type) : type_(type) {}

AMateria::AMateria(const AMateria& other) : type_(other.type_) {}

AMateria& AMateria::operator=(const AMateria& other) {
	if(this != &other) {
		type_ = other.type_;
	}
	return *this;
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const { return type_; }

void	AMateria::use(ICharacter& target) {
	std::cout
	<< "* AMateria is used by "
	<< target.getName() << " *" << std::endl;
}
