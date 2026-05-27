#include "Base.hpp"

Base::~Base() {}

Base* generate(void)
{
    int n = std::rand();
    if(n % 2 == 0)
        return new A;
    else if(n % 5 == 0)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    A*  aptr = dynamic_cast<A *>(p);
    B*  bptr = dynamic_cast<B *>(p);
    C*  cptr = dynamic_cast<C *>(p);

    if(aptr)
        std::cout<<"A"<<std::endl;
    else if(bptr)
        std::cout<<"B"<<std::endl;
    else if(cptr)
        std::cout<<"C"<<std::endl;
}

void identify(Base& p)
{
    try
    {
        A&  aptr = dynamic_cast<A&>(p);
        (void)aptr;
        std::cout<<"A"<<std::endl;
        return;
    }
    catch(const std::exception& e) {}

    try
    {
        B&  bptr = dynamic_cast<B&>(p);
        (void)bptr;
        std::cout<<"B"<<std::endl;
        return;
    }
    catch(const std::exception& e) {}

    try
    {
        C&  cptr = dynamic_cast<C&>(p);
        (void)cptr;
        std::cout<<"C"<<std::endl;
        return;
    }
    catch(const std::exception& e) {}
}