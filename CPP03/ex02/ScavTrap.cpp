#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("")
{
    hit_p = 100;
    energy_p = 50;
    attack_damage = 20;
    std::cout<<"ScavTrap's Default constructor called"<<std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hit_p = 100;
    energy_p = 50;
    attack_damage = 20;
    std::cout<<"ScavTrap's Parameterized constructor called"<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout<<"ScavTrap's Copy constructor called"<<std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout<<"ScavTrap's Copy assignment operator called"<<std::endl;
    if(this != &other)
        ClapTrap::operator=(other);
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if(hit_p>0 && energy_p>0)
    {
        energy_p--;
        std::cout<<"ScavTrap "<<name<<" attacks "<<target<<", causing "<<attack_damage<<" points of damage!"<<std::endl;
    }
    else
        std::cout<<"ScavTrap "<<name<<" didn't have enough hit point or energy point to attack!"<<std::endl;
}

void ScavTrap::guardGate()
{
    std::cout<<"ScavTrap "<<name<<" is now in Gate keeper mode!"<<std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout<<"ScavTrap "<<name<<" destroyed!"<<std::endl;
}