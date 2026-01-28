#include "PhoneBook.hpp"

bool is_valid_i(std::string str)
{
    if(str.empty())
        return false;

    for(size_t i = 0; i < str.size(); i++)
    {
        if (str[i] < 32 || str[i] == 127)
            return false;
    }
    return true;
}

bool is_numeric(std::string temporary_str)
{
    size_t i = 0;
    
    if(temporary_str.empty())
        return false;
    if(temporary_str[i] =='-' || temporary_str[i] =='+')
        i++;
    for(;i < temporary_str.size();i++)
    {
        if(!std::isdigit(temporary_str[i]))
            return false;
    }
    return true;
}

bool is_full_space(std::string str)
{
    for(size_t i = 0; i < str.size(); i++)
    {
        if(str[i] != ' ')
            return true;
    }
    return false;
}
