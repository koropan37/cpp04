#ifndef MATERIASOURCE_HPP_
#define MATERIASOURCE_HPP_

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
 private:
	static const int slot_size_ = 4;
	AMateria*		 inventory_[slot_size_];

 public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();

	void 	  learnMateria(AMateria* mat);
	AMateria* createMateria(std::string const & type);
};

#endif
