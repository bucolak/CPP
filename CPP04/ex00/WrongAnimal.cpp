#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("")
{
    std::cout<<"WrongAnimal Default constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
    std::cout<<"WrongAnimal Copy constructor called"<<std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout<<"WrongAnimal Copy assignment operator called"<<std::endl;
    if(this != &other)
        this->type = other.type;
    return *this;
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std::cout<<"WrongAnimal sound"<<std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"WrongAnimal destructor called"<<std::endl;
}