#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("")
{
    hit_p = 100;
    energy_p = 100;
    attack_damage = 30;
    std::cout<<"FragTrap's Default constructor called"<<std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hit_p = 100;
    energy_p = 100;
    attack_damage = 30;
    std::cout<<"FragTrap's Parameterized constructor called"<<std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout<<"FragTrap's Copy constructor called"<<std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout<<"FragTrap's Copy assignment operator called"<<std::endl;
    if(this != &other)
        ClapTrap::operator=(other);
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout<<"FragTrap "<<name<<" requests a high five!"<<std::endl;
}

FragTrap::~FragTrap()
{
    std::cout<<"FragTrap "<<name<<" destroyed!"<<std::endl;
}