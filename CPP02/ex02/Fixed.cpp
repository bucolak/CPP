#include "Fixed.hpp"

const int Fixed::no_fractional_bits = 8;

Fixed::Fixed()
{
    fixed_point_num = 0;
    std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    this->fixed_point_num = other.fixed_point_num;
    std::cout<<"Copy constructor called"<<std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if(this != &other)
    {
        this->fixed_point_num = other.fixed_point_num;
    }
    std::cout<<"Copy assignment operator called"<<std::endl;
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

Fixed::Fixed(const int inum)
{
    fixed_point_num = (inum<<no_fractional_bits);
    std::cout<<"Int constructor called"<<std::endl;
}

Fixed::Fixed(const float fnum)
{
    fixed_point_num = roundf(fnum * (1 << no_fractional_bits));
    std::cout<<"Float constructor called"<<std::endl;
}

float Fixed::toFloat( void ) const
{
    return (float)fixed_point_num / (1 << no_fractional_bits);
}

int Fixed::toInt( void ) const
{
    return (fixed_point_num >> no_fractional_bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed&obj)
{
    out << obj.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->fixed_point_num > other.fixed_point_num;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->fixed_point_num < other.fixed_point_num;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->fixed_point_num >= other.fixed_point_num;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->fixed_point_num <= other.fixed_point_num;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->fixed_point_num == other.fixed_point_num;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->fixed_point_num != other.fixed_point_num;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed output;
    output.setRawBits(this->fixed_point_num+other.fixed_point_num);
    return output;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed output;
    output.setRawBits(this->fixed_point_num-other.fixed_point_num);
    return output;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed output;
    output.setRawBits((long long)this->fixed_point_num * other.fixed_point_num >> no_fractional_bits);
    return output;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed output;
    output.setRawBits(((long long)this->fixed_point_num << no_fractional_bits) / other.fixed_point_num);
    return output;
}

Fixed& Fixed::operator++()
{
    fixed_point_num++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++fixed_point_num;
    return tmp;
}

Fixed& Fixed::operator--()
{
    fixed_point_num--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    --fixed_point_num;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if(a.fixed_point_num < b.fixed_point_num)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if(a.fixed_point_num < b.fixed_point_num)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if(a.fixed_point_num > b.fixed_point_num)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if(a.fixed_point_num > b.fixed_point_num)
        return a;
    return b;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}