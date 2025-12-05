#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"
#define RESET   "\033[0m"
#define B_RED	"\033[1;31m"
#define B_GREEN "\033[1;32m"
#define B_CYAN  "\033[1;36m"

void printColor(std::string const& str, std::string const& color) {
    std::cout
	<< RESET << "======="
	<< color << str
	<< RESET << "=======" << color << std::endl;
}

int main()
{

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    {
		printColor("SUBJECT", CYAN);
        ICharacter* me = new Character("me");
        AMateria* tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* target = new Character("target");
        me->use(0, *target);
        me->use(1, *target);
        delete target;
        delete me;
        std::cout << std::endl;
    }

    {
		printColor("UNEQUIP", GREEN);
        ICharacter* alice = new Character("Alice");
        AMateria* m1 = src->createMateria("ice");
        alice->equip(m1);
        AMateria* m2 = src->createMateria("cure");
        alice->equip(m2);
		AMateria* m3 = src->createMateria("nothing");
        alice->equip(m3);

        AMateria* floor_item = m1;
		std::cout << "unequip slot 0, " << floor_item->getType() << std::endl;
        alice->unequip(0);

        ICharacter* target = new Character("target");
		std::cout << "use slot 0" << std::endl;
        alice->use(0, *target);
		std::cout << "use slot 1" << std::endl;
        alice->use(1, *target);
		std::cout << "use slot 2" << std::endl;
        alice->use(2, *target);
		std::cout << "use slot 3" << std::endl;
        alice->use(3, *target);

        delete floor_item;
        delete target;
        delete alice;
        std::cout << std::endl;
    }

    {
		printColor("SLOT_SIZE", YELLOW);
        ICharacter* hero = new Character("Hero");
        AMateria* created[5] = { NULL, NULL, NULL, NULL, NULL };

		for (int i = 0; i < 5; ++i) {
			const char* want;
			if (i % 2 == 0) want = "ice";
			else			want = "cure";

			created[i] = src->createMateria(want);
			if (created[i])
				hero->equip(created[i]);
			std::cout
				<< "test " << i << " created: "
				<< created[i]->getType() << std::endl;

		}
        ICharacter* target = new Character("Target");
        for (int i = 0; i < 5; ++i) {
            std::cout << "use slot " << i << ":" << std::endl;
            hero->use(i, *target);
        }
        if (created[4]) delete created[4];
        delete target;
        delete hero;
        std::cout << std::endl;
    }


    {
		printColor("DEEP COPY", MAGENTA);
        Character* orig = new Character("Original");
        AMateria* a = src->createMateria("ice");
        AMateria* b = src->createMateria("cure");
        orig->equip(a);
        orig->equip(b);

        Character copy1(*orig);
		std::cout << "Copy constructor called" << std::endl;
		Character copy2;
		copy2 = *orig;
		std::cout << "Copy assignment called" << std::endl;
        delete orig;
       std::cout << "delete original" << std::endl;

        ICharacter* target = new Character("target");
		std::cout << "use copy1 slot 0" << std::endl;
        copy1.use(0, *target);
		std::cout << "use copy1 slot 1" << std::endl;
        copy1.use(1, *target);
		std::cout << "use copy2 slot 0" << std::endl;
		copy2.use(0, *target);
		std::cout << "use copy2 slot 1" << std::endl;
		copy2.use(1, *target);
        delete target;
		std::cout << std::endl;
    }

    delete src;

    return 0;
}
