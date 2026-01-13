#include "Zombie.hpp"

int main()
{
    Zombie z0("Zombie_0");
    Zombie *z1 = newZombie("Zombie_1");
    randomChump("Zombie_2");

    z1->announce();
    z0.announce();

    delete(z1);
    return 0;
}