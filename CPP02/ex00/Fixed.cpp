#include "Fixed.hpp"

const int Fixed::no_fractional_bits = 8;

Fixed::Fixed()
{
    fixed_point_num = 0;
    std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout<<"Copy constructor called"<<std::endl;
    this->fixed_point_num = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    if(this != &other)
        this->fixed_point_num = other.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return fixed_point_num;
}

void Fixed::setRawBits(int const raw)
{
    fixed_point_num = raw;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}