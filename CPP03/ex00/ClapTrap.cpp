#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name(""), hit_p(10), energy_p(10), attack_damage(0)
{
    std::cout<<"Default constructor called"<<std::endl;
} 

ClapTrap::ClapTrap(std::string name)
    : name(name), hit_p(10), energy_p(10), attack_damage(0)
{
    std::cout<<"A parameterized constructor was called"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : name(other.name), hit_p(other.hit_p), energy_p(other.energy_p), attack_damage(other.attack_damage)
{
    std::cout<<"Copy constructor called"<<std::endl;
    this->name = other.name;
    this->hit_p = other.hit_p;
    this->energy_p = other.energy_p;
    this->attack_damage = other.attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    if(this != &other)
    {
        this->name = other.name;
        this->hit_p = other.hit_p;
        this->energy_p = other.energy_p;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if(hit_p>0 && energy_p>0)
    {
        energy_p--;
        std::cout<<"ClapTrap "<<name<<" attacks "<<target<<", causing "<<attack_damage<<" points of damage!"<<std::endl;
    }
    else
        std::cout<<"ClapTrap "<<name<<" didn't have enough hit point or energy point to attack!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(amount >= (unsigned int)hit_p)
        hit_p = 0;
    else
        hit_p -= amount;
    std::cout<<"ClapTrap "<<name<<" takes "<<amount<<" points of damage!"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(hit_p>0 && energy_p > 0)
    {
        hit_p += amount;
        energy_p--;
        std::cout<<"ClapTrap "<<name<<" repairs itself for "<<amount<<" hit points!"<<std::endl;
    }
    else
        std::cout<<"ClapTrap couldn't repair itself!"<<std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout<<"ClapTrap "<<name<<" destroyed!"<<std::endl;
}