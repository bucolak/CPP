#include "PhoneBook.hpp"

static bool is_valid_i(std::string str)
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

static bool is_numeric(std::string str)
{
    size_t i = 0;
    if(str[i] == '+')
        i++;
    for(; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PhoneBook::add_contact()
{
    std::string input;

    index_of_contacts = size_of_contact % 8;

    while(1)
    {
        std::cout<<"Enter the First Name: ";
        if(!std::getline(std::cin, input))
            return;
        if(!is_valid_i(input))
            continue;
        contact[index_of_contacts].setting_first_name(input);
        break;
    }	
    while(1)
    {
        std::cout<<"Enter the Last Name: ";
        if(!std::getline(std::cin, input))
            return;
        
        if(!is_valid_i(input))
            continue;
        contact[index_of_contacts].setting_last_name(input);
        break;
    }
    while(1)
    {
        std::cout<<"Enter the Nick Name: ";
        if(!std::getline(std::cin, input))
            return;
        if(!is_valid_i(input))
            continue;
        contact[index_of_contacts].setting_nick_name(input);
        break;
    }
    while(1)
    {
        std::cout<<"Enter the Phone Number: ";
        if(!std::getline(std::cin, input))
            return;
        if(!is_valid_i(input))
            continue;
        if(!is_numeric(input))
            continue;
        contact[index_of_contacts].setting_phone_number(input);
        break;
    }
    while(1)
    {
        std::cout<<"Enter the Darkest String: ";
        if(!std::getline(std::cin, input))
            return;
         if(!is_valid_i(input))
            continue;
        contact[index_of_contacts].setting_darkest_string(input);
        break;
    }
    size_of_contact++;
}
