#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(std::time(NULL));

    Intern i;
    AForm *f;

    f = i.makeForm("robotomy request", "target1");
    if(f)
    {
        Bureaucrat b1("First", 1);
        b1.signForm(*f);
        b1.executeForm(*f);
        delete f;
    }

    std::cout<<std::endl;

    f = i.makeForm("shrubbery creation", "target2");
    if(f)
    {
        Bureaucrat b2("Second", 1);
        b2.signForm(*f);
        b2.executeForm(*f);
        delete f;
    }

    std::cout<<std::endl;

    f = i.makeForm("presidential pardon", "target3");
    if(f)
    {
        Bureaucrat b3("Third", 1);
        b3.signForm(*f);
        b3.executeForm(*f);
        delete f;
    }

    std::cout<<std::endl;
    f = i.makeForm("invalid", "A");
    if(f)
        delete f;
    
    return 0;
}