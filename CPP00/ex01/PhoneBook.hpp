#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

class PhoneBook{
private:
    Contact contact[8];
    int oldest_contact_size;
    int size_of_contact;
    
public:
    PhoneBook();

    void add_contact();
    void search_contact();

    ~PhoneBook();
};


#endif