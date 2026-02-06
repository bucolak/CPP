#ifndef CLAP_TRAP
#define CLAP_TRAP

#include <iostream>

class ClapTrap{

    protected:
        std::string name;
        int hit_p;
        int energy_p;
        int attack_damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif