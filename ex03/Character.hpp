#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {
 private:
	std::string 	 name_;
	static const int slot_size_ = 4;
	AMateria*		 inventory_[slot_size_];

 public:
	explicit Character(std::string const& name = "");
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();
	// explicit 単一引数コンストラクタによる暗黙の型変換を禁止
	// Character c = "foo"; がコンパイルエラー（暗黙変換不可）

	std::string const & getName() const;
	void 				equip(AMateria* m);
	void 				unequip(int idx);
	void 				use(int idx, ICharacter& target);

	void 				copyInventory(const Character& other);
	void 				cloneInventory(const Character& other, AMateria *tmp[slot_size_]);
	void 				swapInventory(AMateria *tmp[slot_size_]);
};

#endif
