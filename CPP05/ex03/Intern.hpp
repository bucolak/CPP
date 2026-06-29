#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    private:
        AForm* makeShrubbery(std::string target) const;
        AForm* makeRobotomy(std::string target) const;
        AForm* makePardon(std::string target) const;
    public:
        Intern();
        Intern(const Intern &other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm *makeForm(std::string fName, std::string target);
};

#endif