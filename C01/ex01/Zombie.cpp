// zombies.cpp
#include "zombies.hpp"
#include <iostream>

Zombie::Zombie(void) {}                            
Zombie::Zombie(std::string name) : _name(name) {}
void Zombie::setName(std::string name) { _name = name; }
Zombie::~Zombie() { std::cout << _name << " destroyed" << std::endl; }
void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzzzzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name)
{
    return new Zombie(name);
}

void randomChump(std::string name)
{
    Zombie z(name);
    z.announce();
}