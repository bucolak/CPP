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

void PmergeMe::helper(std::vector<std::pair<int, int> >& pVector, int& spare)
{
    for(size_t i = 0; i < vecContainer.size(); i+=2)
    {
        if((i+1) < pVector.size())
        {
            if(pVector[i] < pVector[i+1])
                pVector.push_back(std::make_pair(pVector[i], pVector[i+1]));
            else
                pVector.push_back(std::make_pair(pVector[i+1], pVector[i]));
        }
    }

    for(size_t i = 0; i < pVector.size(); i+=2)
    {
        if((i+1) < pVector.size())
        {
            if(pVector[i].second > pVector[i+1].second)
            {
                std::pair<int, int> swap = pVector[i];
                pVector[i] = pVector[i+1];
                pVector[i+1] = swap;
            }
        }
    }
    
}

void PmergeMe::JacobsthalRanking_vector(size_t size)
{
    jacobStahlNumbers_vector.push_back(0);
    jacobStahlNumbers_vector.push_back(1);
    for(size_t n = 3; (size_t)jacobStahlNumbers_vector.back() < size; n++)
    {
        int next = jacobStahlNumbers_vector[n-1] + (jacobStahlNumbers_vector[n-2] * 2);
        jacobStahlNumbers_vector.push_back(next);
    }
}

void PmergeMe::sortWvector(char *argv[])
{
    // timeval start, end;
    // gettimeofday(&start, NULL); //----------------------------

    for(int i = 1; argv[i]; i++)
        vecContainer.push_back(atoi(argv[i]));

    int spare;
    std::vector<std::pair<int, int> > pVector; // sola küçük, sağa büyük
    for(size_t i = 0; i < vecContainer.size(); i+=2)
    {
        if((i+1) < vecContainer.size())
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
         std::cout<<"["<<pVector[i].first<<", "<<pVector[i].second<<"]"<<std::endl;
     }
     std::cout<<spare<<std::endl;
     std::cout<<spare<<std::endl;
    helper(pVector);
    for(size_t i = 0; i < pVector.size(); i++)
     {
         std::cout<<"["<<pVector[i].first<<", "<<pVector[i].second<<"]"<<std::endl;
     }
     std::cout<<spare<<std::endl;
   //JacobsthalRanking_vector(pVector.size());

    /*for(size_t i = 0; i < jacobStahlNumbers_vector.size();i++)
    {
        std::cout<<jacobStahlNumbers_vector[i]<<std::endl;
    }*/

    // pVector.insert(pVector.begin(), pVector.)
}

PmergeMe::~PmergeMe() {}
