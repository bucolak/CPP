#include "Animal.hpp"

Animal::Animal() : type("")
{
    std::cout<<"Animal Default constructor called"<<std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
    std::cout<<"Animal Copy constructor called"<<std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
    std::cout<<"Animal Copy assignment operator called"<<std::endl;
    if(this != &other)
        this->type = other.type;
    return *this;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout<<"Animal sound"<<std::endl;
}

Animal::~Animal()
{
    std::cout<<"Animal destructor called"<<std::endl;
}