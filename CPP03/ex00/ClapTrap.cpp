#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name(name), hit_p(10), energy_p(10), attack_damage(0)
{
    std::cout<<"Default constructor called"<<std::endl;
} 

ClapTrap::ClapTrap(std::string name)
    : name(name)
{
    std::cout<<"A parameterized default constructor was called"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout<<"Copy constructor called"<<std::endl;
    this->name = other.name;
    this->hit_p = other.hit_p;
    this->energy_p = other.energy_p;
    this->attack_damage = other.attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
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
        std::cout<<name<<" attacks"<<target<<std::endl;
    }
    else
        std::cout<<name<<" didn't have enough hit point or energy point to attack, so he couldn't attack."<<std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout<<"Destructor called"<<std::endl;
}