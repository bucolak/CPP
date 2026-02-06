#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dt1("Alice");
    DiamondTrap dt2(dt1);
    DiamondTrap dt3("Bob");
    dt3 = dt1;

    std::cout<<std::endl;

    dt1.whoAmI();
    dt1.attack("Target");
    dt1.guardGate();
    dt1.highFivesGuys();
    dt1.takeDamage(33);
    dt1.beRepaired(22);

    std::cout<<std::endl;

    dt2.whoAmI();

    std::cout<<std::endl;

    dt3.whoAmI();

    std::cout<<std::endl;

    ClapTrap *ptr = new DiamondTrap("Kathy");
    ptr->attack("enemy");

    std::cout<<std::endl;
    
    delete ptr;

    return 0;
}