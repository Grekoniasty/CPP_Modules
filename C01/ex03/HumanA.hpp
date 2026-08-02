#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
//Reference, alawys has a weapon, cannot be NULL
class HumanA
{
	private:
		std::string _name;
		Weapon& _weapon;
	public:
		HumanA(std::string name, Weapon& weapon);
		void attack(void) const;
};

#endif
