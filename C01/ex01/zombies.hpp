#ifndef ZOMBIES_HPP
#define ZOMBIES_HPP

#include <iostream>
#include <string>

#define NUM_ZOMBIES 3

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