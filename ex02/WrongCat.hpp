#ifndef WRONGCAT_HPP_
#define WRONGCAT_HPP_

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal {
 private:
    Brain *brain_;

 public:
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat();

    void makeSound() const;

	void printIdeas() const;
  	void addIdea(const std::string& idea);
};

#endif
