#ifndef WRONGDOG_HPP_
#define WRONGDOG_HPP_

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
 public:
	WrongDog();
	WrongDog(const WrongDog& other);
	WrongDog& operator=(const WrongDog& other);
	~WrongDog();

	void makeSound() const;
};

#endif
