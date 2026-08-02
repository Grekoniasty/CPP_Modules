#include "zombies.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie()
{
    std::cout << _name << " destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzzzzzzR..." << std::endl;
}

Zombie* newZombie(std::string name)
{
    return new Zombie(name);
}

void randomChump(std::string name)   // bez średnika!
{
    Zombie z(name);
    z.announce();
}