#include "Character.hpp"
#include <iostream>

Character::Character(std::string const& name) : name_(name), inventory_() {}

Character::Character(const Character& other) : name_(other.name_), inventory_() {
	copyInventory(other);
}

Character& Character::operator=(const Character& other) {
	if(this != &other) {
		name_ = other.name_;
		copyInventory(other);
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < slot_size_; ++i) {
		delete inventory_[i];
		inventory_[i] = NULL;
	}
}

std::string const& Character::getName() const { return name_; }

void Character::equip(AMateria* m) {
	if(!m) return ;
	for (int i = 0; i < slot_size_; ++i) {
		if(inventory_[i] == NULL) {
			inventory_[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if(0 <= idx && idx < slot_size_ && inventory_[idx])
		inventory_[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
if(0 <= idx && idx < slot_size_ && inventory_[idx])
	inventory_[idx]->use(target);
}


void Character::copyInventory(const Character& other) {
	if(&other != this) {
		AMateria* tmp[slot_size_];
		for (int i = 0; i < slot_size_; ++i) tmp[i] = NULL;

		try {
			cloneInventory(other, tmp);
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

void Character::cloneInventory(const Character& other, AMateria *tmp[slot_size_]) {
		for (int i = 0; i < slot_size_; ++i) {
				if (other.inventory_[i]) {
					tmp[i] = other.inventory_[i]->clone();
				}
		}
}

void Character::swapInventory(AMateria *tmp[slot_size_]) {
	for (int i = 0; i < slot_size_; ++i) {
		delete inventory_[i];
		inventory_[i] = tmp[i];
	}
}
