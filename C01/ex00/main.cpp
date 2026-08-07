#include "zombies.hpp"

int main(void)
{
    randomChump("Benjamin Netanyahu");
    Zombie* heap = newZombie("Donald J Trump");
    heap->announce();
    delete heap;
    return 0;
}