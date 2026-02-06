#include "FragTrap.hpp"

int main()
{
    FragTrap st1("A");
    FragTrap st2("B");
    FragTrap st3(st1);
    FragTrap st4;
    st4 = st1;

    st1.attack("B");
    st2.takeDamage(22);

    st2.attack("A");
    st2.takeDamage(200);
    st2.attack("A");
    st2.beRepaired(20);

    st1.highFivesGuys();
    return 0;
}