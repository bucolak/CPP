#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact{
private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_string;

public:
    Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number,  std::string darkest_string)
    {
        this->first_name=first_name;
        this->last_name=last_name;
        this->nick_name=nick_name;
        this->phone_number=phone_number;
        this->darkest_string=darkest_string;
    }

    ~Contact(){};
};

#endif