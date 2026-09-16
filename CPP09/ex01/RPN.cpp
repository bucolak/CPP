#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
    : container(other.container) {}

RPN& RPN::operator=(const RPN& other)
{
    if(this != &other)
    {
        this->container = other.container;
    }
    return *this;
}

void RPN::get_result(std::string str)
{
    try 
    {
        for(size_t i = 0; i < str.size(); i++)
        {
            if(std::isdigit(str[i]))
                container.push(str[i] - '0');
            else if(str[i ]== ' ')
                continue;
            else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            {
                if(container.size() < 2)
                    throw std::runtime_error("Error");
                int num1 = container.top();
                container.pop();
                int num2 = container.top();
                container.pop();
                int result;
                if(str[i] == '+')
                    result = num1+num2;
                else if(str[i] == '-')
                    result = num2-num1;
                else if(str[i] == '*')
                    result = num2*num1;
                else if(str[i] == '/')
                {
                    if(num1 == 0)
                        throw std::runtime_error("Error");
                    result = num2/num1;
                }
                container.push(result);
            }
            else
                throw std::runtime_error("Error");
        }
        if(container.size() != 1)
            throw std::runtime_error("Error");
        std::cout<<container.top()<<std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
}

RPN::~RPN() {}