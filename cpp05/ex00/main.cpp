#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b1;
    Bureaucrat b2("Jake", 1);
    Bureaucrat b3(b2);
    b1 = b2;

    std::cout<<b3<<std::endl;

    try
    {
        Bureaucrat a0("Sam0", 151);
        Bureaucrat a1("Sam1", 0);
    }
    catch(std::exception& e)
    {
        std::cout <<"1 -> "<< e.what() << std::endl;
    }

    try
    {
        Bureaucrat a2("Sam2", 0);
    }
    catch(std::exception& e)
    {
        std::cout <<"2 -> "<< e.what() << std::endl;
    }

    try
    {
        Bureaucrat a3("Sam3", 1);
        a3.incGrade(1);
    }
    catch(std::exception& e)
    {
        std::cout <<"3 -> "<< e.what() << std::endl;
    }

    try
    {
        Bureaucrat a4("Sam4", 150);
        a4.decGrade(1);
    }
    catch(std::exception& e)
    {
        std::cout <<"4 -> "<< e.what() << std::endl;
    }
    return 0;
}