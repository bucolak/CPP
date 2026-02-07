#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout<<"WrongCat Default constructor called"<<std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other)
{
    this->type = other.type;
    std::cout<<"WrongCat Copy constructor called"<<std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    std::cout<<"WrongCat Copy assignment operator called"<<std::endl;
    if(this != &other)
        this->type = other.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout<<"WrongCat "<<type<<" says Meow Meow!"<<std::endl;
}

WrongCat::~WrongCat()
{
    std::cout<<"WrongCat destructor called"<<std::endl;
}