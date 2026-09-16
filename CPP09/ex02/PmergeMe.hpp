#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>
#include <cctype>

class PmergeMe
{
    private:
        std::vector<int> vecContainerUnsorted;
        std::vector<int> vecContainerSorted;
        std::vector<int> jacobStahlNumbers_vector;

        std::deque<int> deqContainerUnsorted;
        std::deque<int> deqContainerSorted;
        std::deque<int> jacobStahlNumbers_deque;
        
        double time_vector;
        double time_deque;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void argv_ctrl(char *argv[]);

        void sortWvector(char *argv[]);
        void sortWdeque(char *argv[]);

        void helperVector(std::vector<std::pair<int, int> >& pVector);
        void JacobsthalRanking_vector(size_t size);
        void helperDequeu(std::deque<std::pair<int, int> >& pDeque);
        void JacobsthalRanking_deque(size_t size);

        void printResults();
};

#endif