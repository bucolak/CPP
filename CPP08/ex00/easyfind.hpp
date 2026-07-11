#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>
#include <deque>

template <typename T>
typename T::iterator easyfind(T& cntr, int n)
{
    typename T::iterator it;
    it = std::find(cntr.begin(), cntr.end(), n);
    if(it == cntr.end())
        throw std::runtime_error("Value not found!");
    return it;
}

#endif