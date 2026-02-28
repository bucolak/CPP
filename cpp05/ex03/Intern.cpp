#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) 
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other) 
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string fName, std::string target)
{
    std::string forms[3] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm"
    };

    int i = 0;
    for(; i < 3; i++)
    {
        if(forms[i] == fName)
            break;
    }

    switch(i)
    {
        case 0:
            std::cout<<"Intern creates ShrubberyCreationForm"<<std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates RobotomyRequestForm" << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates PresidentialPardonForm" << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Intern couldn't find form " << fName << std::endl;
            return NULL;
    }
}