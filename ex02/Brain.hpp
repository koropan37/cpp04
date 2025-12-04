#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include "Animal.hpp"

class Brain {
 private:
	std::string ideas[100];
	int			i_;
 public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	std::string getIdeas(int i) const;
	void		addIdeas(const std::string& idea);
};

#endif
