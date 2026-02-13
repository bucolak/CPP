#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b1;
    Bureaucrat b2("Jake", 1);
    Bureaucrat b3(b2);
    b1 = b2;

    try
    {
        Bureaucrat dnm("aaaa", 151);
        Bureaucrat dnm2("bbbb", 0);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat dnm2("bbbb", 0);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}