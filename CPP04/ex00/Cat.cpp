#include "Cat.hpp"

Cat::Cat()
{
    std::cout<<"Cat Default constructor called"<<std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    this->type = other.type;
    std::cout<<"Cat Copy constructor called"<<std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout<<"Cat Copy assignment operator called"<<std::endl;
    if(this != &other)
        this->type = other.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout<<"Cat "<<type<<" says Meow Meow!"<<std::endl;
}

Cat::~Cat()
{
    std::cout<<"Cat destructor called"<<std::endl;
}