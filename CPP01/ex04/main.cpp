#include "Sed.hpp"

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        std::cout<<"Program execution format: ./sed <filename> <s1> <s2>"<<std::endl;
        return 0;
    }
    Sed s(argv[2], argv[3], argv[1]);
    s.replace();
    return 0;
}
