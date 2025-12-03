#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <string>

class Animal {
 protected:
	std::string type;

 public:
	Animal();
	Animal(const std::string& type);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	virtual void makeSound() const;
	std::string getType() const;
};

#endif
