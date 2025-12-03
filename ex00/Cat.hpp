#ifndef CAT_HPP_
#define CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal {
 public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	void makeSound() const;
};

#endif
