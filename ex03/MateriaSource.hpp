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

	void 	  learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);

	void	copyInventory(const MateriaSource&other);
	void	cloneInventory(const MateriaSource&other, AMateria *tmp[slot_size_]);
	void	swapInventory(AMateria *tmp[slot_size_]);
};

#endif
