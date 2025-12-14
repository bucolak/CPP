#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact{
private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_string;

public:
    Contact();

    Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number,  std::string darkest_string);

    void setting_first_name(std::string first_name);
    void setting_last_name(std::string last_name);
    void setting_nick_name(std::string nick_name);
    void setting_phone_number(std::string phone_number);
	void setting_darkest_string(std::string darkest_string);

    std::string getting_first_name();
    std::string getting_last_name();
    std::string getting_nick_name();
    std::string getting_phone_number();
    std::string getting_darkest_string();

    ~Contact();
};

#endif