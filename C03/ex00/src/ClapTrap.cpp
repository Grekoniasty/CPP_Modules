#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoint = 10;
	_attackDamage = 0;
	std::cout << _name << " entered the Fight Zone. LEEETSSS GETTT READDYYY TO RUMMMBBBLEEE! " << std::endl;
}

ClapTrap::~ClapTrap()
{
	std:: cout << _name << " had a good fight. Well he might do better next time. " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << _name << " was cloned into the Fight Zone!" << std::endl;
}

ClapTrap &ClapTrap::operator =(const ClapTrap &other)
{
	if (this == &other)
		return *this;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoint = other._energyPoint;
	_attackDamage = other._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << _name << " is gone already, leave him be..." << std::endl;
		return;
	}
	if (_energyPoint <= 0)
	{
		std::cout << _name << " is too tired to beat him up boss... " << std::endl;
		return;
	}
	_energyPoint--;
	std::cout << _name << " smacks " << target << ", with a powerful bitchslap and deals " << _attackDamage << " points of damage!" << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << _name << " looks like is about to move!!! Nuh he is still dead." << std::endl;
		return;
	}
	if (_energyPoint <= 0)
	{
		std::cout << _name << " is trying to clean himself up after a hard beating. But he is too slow to do so... " << std::endl;
		return;
	}
	_energyPoint--;
	_hitPoints += amount;
	std::cout << _name << " patched up " << amount << " wounds. Now he has " << _hitPoints << " hit points. " << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << _name << "'s corpse are getting smacked, WHY? " << std::endl;
		return;
	}
	_hitPoints -= amount;
	if (_hitPoints <= 0)
	{
		std::cout << _name << " is gone" << std::endl;
		return;
	}
	std::cout << _name << " was slapped for " << amount << " damage" << std::endl;
}
