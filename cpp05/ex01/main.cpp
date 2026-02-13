#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat success_b("Kathy", 30);
        Form success_f("A", 50, 20);
        success_b.signForm(success_f);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat unsuccess_b("Olivia", 100);
        Form unsuccess_f("B", 50,30);
        unsuccess_b.signForm(unsuccess_f);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat high_success_b("Bella", 1);
        Form high_success_f("B", 1, 2);
        high_success_b.signForm(high_success_f);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}