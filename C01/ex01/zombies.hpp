#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

#define NUM_ZOMBIES 140

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie();
        void setName(std::string name);
        void announce(void);
};

Zombie* newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);
void    randomChump(std::string name);

#endif