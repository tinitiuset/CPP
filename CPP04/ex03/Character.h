#ifndef CHARACTER_H
#define CHARACTER_H

#ifndef ICHARACTER_H
#include "ICharacter.h"
#endif

class Character: public ICharacter {

	public:
		Character();
		Character(std::string const & name);
		Character(Character const &character);
		Character & operator=(Character const &character);
		virtual ~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
	private:
		std::string _name;
		AMateria *_inventory[4];
		int _count;
		void _deleteInventory();
		void _copyInventory(Character const &character);
};


#endif
