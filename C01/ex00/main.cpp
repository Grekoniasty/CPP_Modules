#include "zombies.hpp"

int main(void)
{
    randomChump("Marie Curie");
    Zombie* heap = newZombie("Saddam Hussein");
    heap->announce();
    delete heap;
    return 0;
}