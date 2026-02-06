#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("_clap_name"), ScavTrap(), FragTrap(), name("")
{
    std::cout<<"DiamondTrap's Default constructor called"<<std::endl;
    hit_p = FragTrap::hit_p;
    energy_p = ScavTrap::energy_p;
    attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name+"_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    std::cout<<"DiamondTrap's Parameterized constructor called"<<std::endl;
    hit_p = FragTrap::hit_p;
    energy_p = ScavTrap::energy_p;
    attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    std::cout<<"DiamondTrap's Copy constructor called"<<std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout<<"DiamondTrap's Copy assignment operator called"<<std::endl;
    if(this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout<<"My DiamondTrap name is "<<name<<" and my ClapTrap name is "<<ClapTrap::name<<std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout<<"DiamondTrap "<<name<<" destroyed!"<<std::endl;
}
