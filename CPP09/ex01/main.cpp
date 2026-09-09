#include "RPN.hpp"

int main(int argc, char* argv[])
{
    if(argc !=2)
    {
        std::cout<<"Usage: ./program \"numbers\""<<std::endl;
        return 0; 
    }
    RPN r;
    r.get_result(argv[1]);
}