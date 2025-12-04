#ifndef CAT_HPP_
#define CAT_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
	Brain *brain_;

 public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	void makeSound() const;

	void printIdeas() const;
  	void addIdea(const std::string& idea);
};

#endif
