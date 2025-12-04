#ifndef AMATERIA_HPP_
#define AMATERIA_HPP_

#include "ICharacter.hpp"
#include <string>

class AMateria {
 protected:
	std::string type_;

 public:
 	AMateria();
	AMateria(std::string const& type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();

	std::string const& getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif
