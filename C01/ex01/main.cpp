#include "zombies.hpp"

int main(void)
{
    int N = NUM_ZOMBIES;
    Zombie *horde = zombieHorde(N, "Horde");
    for (int i = 0; i < N; i++)
        horde[i].announce();
    delete[] horde;

    return 0;
}
