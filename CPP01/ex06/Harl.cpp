#include "Harl.hpp"

void Harl::debug()
{
    std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"<<std::endl;
}

void Harl::info()
{
    std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}

void Harl::warning()
{
    std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."<<std::endl;
}

void Harl::error()
{
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcs[4])() = {
        &Harl::debug,
        &Harl::warning,
        &Harl::info,
        &Harl::error
    };

    for(int i = 0;i< 4;i++)
    {
        if(levels[i] == level)
        {
            (this->*funcs[i])();
            return ;
        }
    }
    std::cout<<"Invalid level input: "<<level<<std::endl;
}

void Harl::filter(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int index = -1;

    for(int i = 0;i < 4;i++)
    {
        if (level == levels[i])
        {
            index = i;
            break;
        }
    }

    switch(index)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            this->complain("DEBUG");
            // fall through
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            this->complain("INFO");
            // fall through
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            this->complain("WARNING");
            // fall through
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            this->complain("ERROR");
            // fall through
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

// int topla(int a, int b) { return a + b; }

// int (*fonksiyon_ptr)(int, int) = &topla;  // topla'nın adresini tuttuk