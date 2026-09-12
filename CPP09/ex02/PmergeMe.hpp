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
        std::deque<int> deqContainer;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void sortWvector(char *argv[]);
        void sortWdeque(char *argv[]);
};

#endif