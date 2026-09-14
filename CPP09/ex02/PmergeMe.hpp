#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <cstdlib>

class PmergeMe
{
    private:
        std::vector<int> vecContainer;
        std::vector<int> jacobStahlNumbers_vector;
        std::deque<int> deqContainer;
        std::deque<int> jacobStahlNumbers_deque;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void sortWvector(char *argv[]);
        void sortWdeque(char *argv[]);

        void helper(std::vector<std::pair<int, int> >& pVector, int& spare);
        void JacobsthalRanking_vector(size_t size);
};

#endif