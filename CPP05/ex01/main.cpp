#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

    Bureaucrat b1("Kathy1", 30);
    Form f1("A", 50, 20);

    std::cout<<b1<<std::endl;
    std::cout<<f1<<std::endl;

    try
    {
        Form f2("FormA", 0, 50);
    }
    catch (std::exception &e)
    {
        std::cout << "FormA : " << e.what() << std::endl;
    }

    try
    {
        Form f3("FormB", 50, 151);
    }
    catch (std::exception &e)
    {
        std::cout << "FormB : " << e.what() << std::endl;
    }

    Bureaucrat b2("Kathy2", 50);
    Bureaucrat b3("Kathy3", 150);

    Form f4("FormC", 50, 30);

    b2.signForm(f4);
    b3.signForm(f4);

    return 0;
}