#include "Base.hpp"

int main()
{
    std::srand(std::time(0));

    Base* ptr = generate();

    std::cout << "Pointer identify: ";
    identify(ptr);

    std::cout << "Reference identify: ";
    identify(*ptr);

    delete ptr;

    return 0;
}
