#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    vecContainerUnsorted = other.vecContainerUnsorted;
    vecContainerSorted = other.vecContainerSorted;
    deqContainerUnsorted = other.deqContainerUnsorted;
    deqContainerSorted = other.deqContainerSorted;
    jacobStahlNumbers_vector = other.jacobStahlNumbers_vector;
    jacobStahlNumbers_deque = other.jacobStahlNumbers_deque;
    time_vector = other.time_vector;
    time_deque = other.time_deque;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if(this != &other)
    {
        vecContainerUnsorted = other.vecContainerUnsorted;
        vecContainerSorted = other.vecContainerSorted;
        deqContainerUnsorted = other.deqContainerUnsorted;
        deqContainerSorted = other.deqContainerSorted;
        jacobStahlNumbers_vector = other.jacobStahlNumbers_vector;
        jacobStahlNumbers_deque = other.jacobStahlNumbers_deque;
        time_vector = other.time_vector;
        time_deque = other.time_deque;
    }
    return *this;
}

void PmergeMe::argv_ctrl(char *argv[])
{
    for(int i = 1; argv[i]; i++)
    {
        std::string arg = argv[i];
        if(arg.empty() || arg[0] == '-')
            throw std::invalid_argument("Error: Empty or Not a positive number.");
        
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!isdigit(arg[j]))
                throw std::invalid_argument("Error: Not a number.");
        }

        long val = atol(arg.c_str());
        if (val > 2147483647)
            throw std::invalid_argument("Error: Exceeded the max integer.");
    }
}

void PmergeMe::helperVector(std::vector<std::pair<int, int> >& pVector)
{
    if(pVector.size() == 1 || pVector.size() == 0)
        return ;
    std::vector<std::pair<int, int> > one;
    std::vector<std::pair<int, int> > two;
    for(size_t i = 0; i < pVector.size(); i++)
    {
        if(i < pVector.size()/2)
            one.push_back(pVector[i]);
        else
            two.push_back(pVector[i]);
    }

    helperVector(one);
    helperVector(two);
    size_t p = 0;
    size_t o = 0;
    size_t t = 0;
    while((o < one.size()) && (t < two.size()))
    {
        if(one[o].second < two[t].second)
        {
            pVector[p] = one[o];
            o++;
            p++;
        }
        else
        {
            pVector[p] = two[t];
            t++;
            p++;
        }
    }
    while(o < one.size())
    {
        pVector[p] = one[o];
        p++;
        o++;
    }
    while(t < two.size())
    {
        pVector[p] = two[t];
        p++;
        t++;
    }
}


void PmergeMe::JacobsthalRanking_vector(size_t size)
{
    jacobStahlNumbers_vector.push_back(0);
    jacobStahlNumbers_vector.push_back(1);
    for(size_t n = 2; (size_t)jacobStahlNumbers_vector.back() < size; n++)
    {
        int next = jacobStahlNumbers_vector[n-1] + (jacobStahlNumbers_vector[n-2] * 2);
        jacobStahlNumbers_vector.push_back(next);
    }
}

void PmergeMe::sortWvector(char *argv[])
{
    timeval start, end;
    gettimeofday(&start, NULL); //----------------------------

    for(int i = 1; argv[i]; i++)
        vecContainerUnsorted.push_back(atoi(argv[i]));

    int spare = -1;
    std::vector<std::pair<int, int> > pVector;
    for(size_t i = 0; i < vecContainerUnsorted.size(); i+=2)
    {
        if((i+1) < vecContainerUnsorted.size())
        {
            if(vecContainerUnsorted[i] < vecContainerUnsorted[i+1])
                pVector.push_back(std::make_pair(vecContainerUnsorted[i], vecContainerUnsorted[i+1]));
            else
                pVector.push_back(std::make_pair(vecContainerUnsorted[i+1], vecContainerUnsorted[i]));
        }
        else
            spare = vecContainerUnsorted[i];
    }
   
    helperVector(pVector);

    JacobsthalRanking_vector(pVector.size());

    std::vector<int> mainChain;
    if(pVector.size()>0)
    {
        mainChain.push_back(pVector[0].first);
        for(size_t i = 0; i < pVector.size(); i++)
            mainChain.push_back(pVector[i].second);
        
        int previousJacob = 1;
        for(size_t i = 3; i < jacobStahlNumbers_vector.size(); i++)
        {
            int startIndex = jacobStahlNumbers_vector[i] - 1;
            if(jacobStahlNumbers_vector[i] >= (int)pVector.size())
                startIndex = pVector.size() -1;
            for(int j = startIndex; j >= previousJacob; j--)
            {
                int add = pVector[j].first;
                int search = pVector[j].second;
    
                std::vector<int>::iterator limit = std::find(mainChain.begin(), mainChain.end(), search);
                std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), limit, add);
                mainChain.insert(it, add);
            }
            previousJacob = jacobStahlNumbers_vector[i];
        }
    }
    if(spare >= 0)
    {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), spare);
        mainChain.insert(it, spare);
    }

    gettimeofday(&end, NULL); //----------------------------
    vecContainerSorted = mainChain;
    time_vector = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

//----------------Deque---------------------------

void PmergeMe::helperDequeu(std::deque<std::pair<int, int> >& pDeque)
{
    if(pDeque.size() == 1 || pDeque.size() == 0)
        return ;
    std::deque<std::pair<int, int> > one;
    std::deque<std::pair<int, int> > two;
    for(size_t i = 0; i < pDeque.size(); i++)
    {
        if(i < pDeque.size()/2)
            one.push_back(pDeque[i]);
        else
            two.push_back(pDeque[i]);
    }

    helperDequeu(one);
    helperDequeu(two);
    size_t p = 0;
    size_t o = 0;
    size_t t = 0;
    while((o < one.size()) && (t < two.size()))
    {
        if(one[o].second < two[t].second)
        {
            pDeque[p] = one[o];
            o++;
            p++;
        }
        else
        {
            pDeque[p] = two[t];
            t++;
            p++;
        }
    }
    while(o < one.size())
    {
        pDeque[p] = one[o];
        p++;
        o++;
    }
    while(t < two.size())
    {
        pDeque[p] = two[t];
        p++;
        t++;
    }
}


void PmergeMe::JacobsthalRanking_deque(size_t size)
{
    jacobStahlNumbers_deque.push_back(0);
    jacobStahlNumbers_deque.push_back(1);
    for(size_t n = 2; (size_t)jacobStahlNumbers_deque.back() < size; n++)
    {
        int next = jacobStahlNumbers_deque[n-1] + (jacobStahlNumbers_deque[n-2] * 2);
        jacobStahlNumbers_deque.push_back(next);
    }
}



void PmergeMe::sortWdeque(char *argv[])
{
    timeval start, end;
    gettimeofday(&start, NULL); //----------------------------

    for(int i = 1; argv[i]; i++)
        deqContainerUnsorted.push_back(atoi(argv[i]));

    int spare = -1;
    (void) spare;
    std::deque<std::pair<int, int> > pDeque; // sola küçük, sağa büyük
    for(size_t i = 0; i < deqContainerUnsorted.size(); i+=2)
    {
        if((i+1) < deqContainerUnsorted.size())
        {
            if(deqContainerUnsorted[i] < deqContainerUnsorted[i+1])
                pDeque.push_back(std::make_pair(deqContainerUnsorted[i], deqContainerUnsorted[i+1]));
            else
                pDeque.push_back(std::make_pair(deqContainerUnsorted[i+1], deqContainerUnsorted[i]));
        }
        else
            spare = deqContainerUnsorted[i];
    }
   
    helperDequeu(pDeque);

    JacobsthalRanking_deque(pDeque.size());

    std::deque<int> mainChain;
    if(pDeque.size()>0)
    {
        mainChain.push_back(pDeque[0].first);
        for(size_t i = 0; i < pDeque.size(); i++)
            mainChain.push_back(pDeque[i].second);
        
        int previousJacob = 1;
        for(size_t i = 3; i < jacobStahlNumbers_deque.size(); i++)
        {
            int startIndex = jacobStahlNumbers_deque[i] - 1;
            if(jacobStahlNumbers_deque[i] >= (int)pDeque.size())
                startIndex = pDeque.size() -1;
            for(int j = startIndex; j >= previousJacob; j--)
            {
                int add = pDeque[j].first;
                int search = pDeque[j].second;
    
                std::deque<int>::iterator limit = std::find(mainChain.begin(), mainChain.end(), search);
                std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), limit, add);
                mainChain.insert(it, add);
            }
            previousJacob = jacobStahlNumbers_deque[i];
        }
    }
    if(spare >= 0)
    {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), spare);
        mainChain.insert(it, spare);
    }

    gettimeofday(&end, NULL); //----------------------------
    deqContainerSorted = mainChain;
    time_deque = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

//----------------Printer-------------------------
void PmergeMe::printResults()
{
    std::cout << "Before: ";
    for(size_t i = 0; i < vecContainerUnsorted.size(); i++)
        std::cout << vecContainerUnsorted[i] << " ";
    std::cout << "\n";

    std::cout << "After: ";
    for(size_t i = 0; i < vecContainerSorted.size(); i++)
        std::cout << vecContainerSorted[i] << " ";
    std::cout << "\n";

    std::cout << "Time to process a range of " << vecContainerUnsorted.size() << " elements with std::vector : " << time_vector << " us\n";
    std::cout << "Time to process a range of " << deqContainerSorted.size() << " elements with std::deque : " << time_deque << " us\n";
}

PmergeMe::~PmergeMe() {}
