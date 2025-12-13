#include "Contact.hpp"

Contact::Contact(){};

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number,  std::string darkest_string)
{
    this->first_name=first_name;
    this->last_name=last_name;
    this->nick_name=nick_name;
    this->phone_number=phone_number;
    this->darkest_string=darkest_string;
}

void Contact::setting_first_name(std::string first_name)
{
    this->first_name = first_name;
}

void Contact::setting_last_name(std::string last_name)
{
    this->last_name = last_name;
}

void Contact::setting_nick_name(std::string nick_name)
{
    this->nick_name = nick_name;
}

void Contact::setting_phone_number(std::string phone_number)
{
    this->phone_number = phone_number;
}

void Contact::setting_darkest_string(std::string darkest_string)
{
    this->darkest_string = darkest_string;
}

std::string Contact::getting_first_name()
{
    return first_name;
}

std::string Contact::getting_last_name()
{
    return last_name;
}

std::string Contact::getting_nick_name()
{
    return nick_name;
}

std::string Contact::getting_phone_number()
{
    return phone_number;
}

std::string Contact::getting_darkest_string()
{
    return darkest_string;
}

Contact::~Contact(){};