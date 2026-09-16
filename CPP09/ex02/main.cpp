#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: Usage: ./Program [Numbers]" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe p;
        p.argv_ctrl(argv);
        p.sortWvector(argv);
        p.sortWdeque(argv);
        p.printResults();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}