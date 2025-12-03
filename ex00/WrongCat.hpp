#ifndef WRONGCAT_HPP_
#define WRONGCAT_HPP_

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
	WrongCat();
	WrongCat(const WrongCat& other);
	WrongCat& operator=(const WrongCat& other);
	~WrongCat();

	void makeSound() const;
};

#endif
