#include "ScavTrap.hpp"

int main()
{
    ScavTrap st1("A");
    ScavTrap st2("B");
    ScavTrap st3(st1);
    ScavTrap st4;
    st4 = st1;

    st1.attack("B");
    st2.takeDamage(22);

    st2.attack("A");
    st2.takeDamage(200);
    st2.attack("A");
    st2.beRepaired(20);

    st1.guardGate();
    return 0;
}