#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void print_members(T &v)
{
    std::cout << v;
}

template<typename T>
void iter(T *adr, const int &lngth, void (*print_members)(T&))
{
    for(int i = 0; i < lngth; i++)
    {
        print_members(adr[i]);
        if(i != lngth - 1)
			std::cout << " , ";
    }
}

#endif