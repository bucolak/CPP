#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    vecContainer = other.vecContainer;
    deqContainer = other.deqContainer;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if(this != &other)
    {
        vecContainer = other.vecContainer;
        deqContainer = other.deqContainer;
    }
    return *this;
}

void PmergeMe::sortWvector(char *argv[])
{
    // timeval start, end;
    // gettimeofday(&start, NULL); //----------------------------

    for(int i = 1; argv[i]; i++)
        vecContainer.push_back(atoi(argv[i]));
    
    std::vector<std::pair<int, int> > pVector; // sola küçük, sağa büyük
    int spare;
    for(size_t i = 0; i < vecContainer.size(); i+=2)
    {
        if(vecContainer[i+1])
        {
            if(vecContainer[i] < vecContainer[i+1])
                pVector.push_back(std::make_pair(vecContainer[i], vecContainer[i+1]));
            else
                pVector.push_back(std::make_pair(vecContainer[i+1], vecContainer[i]));
        }
        else
            spare = vecContainer[i];
    }

    for(size_t i = 0; i < pVector.size(); i++)
    {
        
    }
}

PmergeMe::~PmergeMe() {}
