#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN
{
    private:
        std::stack<int> container;
    public:
        RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void get_result(std::string str);
};

#endif


