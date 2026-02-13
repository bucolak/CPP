#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));

    try
    {
        Bureaucrat a("A", 1);
        Bureaucrat b("B", 150);

        ShrubberyCreationForm s("Garden");
        RobotomyRequestForm r("Targett");
        PresidentialPardonForm p("Jim");

        b.signForm(s);
        a.signForm(s);
        
        b.executeForm(s);
        a.executeForm(s);

        a.signForm(r);
        a.executeForm(r);

        a.signForm(p);
        a.executeForm(p);
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    
}