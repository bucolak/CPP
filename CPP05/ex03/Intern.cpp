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

AForm *Intern::makeShrubbery(std::string target) const
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(std::string target) const 
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePardon(std::string target) const 
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string fName, std::string target)
{
    std::string forms[3] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    AForm* (Intern::*function[3])(std::string) const = {
        &Intern::makeRobotomy,
        &Intern::makePardon,
        &Intern::makeShrubbery
    };

    for(int i = 0; i < 3; i++)
    {
        if(forms[i] == fName)
        {
            std::cout<<"Intern creates "<<fName<<std::endl;
            return(this->*function[i])(target);
        }
    }

    std::cout << "Intern couldn't find form " << fName << std::endl;
    return NULL;
}