#ifndef WRONGDOG_HPP_
#define WRONGDOG_HPP_

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongDog : public WrongAnimal {
 private:
	Brain *brain_;

 public:
	WrongDog();
	WrongDog(const WrongDog& other);
	WrongDog& operator=(const WrongDog& other);
	~WrongDog();

	void makeSound() const;
};

#endif
