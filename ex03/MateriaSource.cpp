#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : inventory_() {}

MateriaSource::MateriaSource(const MateriaSource& other) : inventory_() {
	copyInventory(other);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if(this != &other)
		copyInventory(other);
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < slot_size_; ++i) {
		delete inventory_[i];
		inventory_[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if(!m) return ;
	for (int i = 0; i < slot_size_; ++i) {
		if(inventory_[i] == NULL) {
			inventory_[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for(int i = 0; i < slot_size_; ++i) {
		if(inventory_[i] && inventory_[i]->getType() == type)
			return inventory_[i]->clone();
	}
	return NULL;
}

void MateriaSource::copyInventory(const MateriaSource& other) {
	if(&other != this) {
		AMateria* tmp[slot_size_];
		for (int i = 0; i < slot_size_; ++i) tmp[i] = NULL;

		try {
			cloneInventory(other,tmp);
		} catch(const std::bad_alloc& e) {
			for (int i = 0; i < slot_size_; ++i) delete tmp[i];
			std::cerr << e.what() << std::endl;
			return;
		}
		swapInventory(tmp);
    }
    return;
}
//new が失敗したときのエラー処理

void MateriaSource::cloneInventory(const MateriaSource& other, AMateria *tmp[slot_size_]) {
		for (int i = 0; i < slot_size_; ++i) {
				if (other.inventory_[i]) {
					tmp[i] = other.inventory_[i]->clone();
				}
		}
}

void MateriaSource::swapInventory(AMateria *tmp[slot_size_]) {
	for (int i = 0; i < slot_size_; ++i) {
		delete inventory_[i];
		inventory_[i] = tmp[i];
	}
}
