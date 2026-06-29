#include "iter.hpp"

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};

    iter(numbers, 5, print_members);
    std::cout << std::endl;

    std::string words[] = {"hello", "world", "cpp"};
    iter(words, 3, print_members);
    std::cout << std::endl;
    
    return 0;
}