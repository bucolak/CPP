#include "ClapTrap.hpp"

int main()
{
    ClapTrap cp1("A");
    ClapTrap cp2("B");
    ClapTrap cp3(cp1);
    ClapTrap cp4;
    cp4 = cp1;

    cp1.attack("B");
    cp1.takeDamage(2);
    cp1.beRepaired(4);

    cp2.attack("A");
    cp2.takeDamage(10);
    cp2.attack("A");
    cp2.beRepaired(5);
}