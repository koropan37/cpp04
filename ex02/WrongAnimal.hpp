#ifndef WRONGANIMAL_HPP_
#define WRONGANIMAL_HPP_

#include <string>

class WrongAnimal {
 protected:
	std::string type;

 public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal(const std::string& type);
	WrongAnimal &operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();

	void makeSound() const;
	std::string getType() const;
};

#endif
