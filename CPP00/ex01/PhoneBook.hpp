#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

class PhoneBook{
private:
    Contact contact[8];
    int size_of_contact;
    int index_of_contacts;
    
public:
    PhoneBook();

    void add_contact();
    void search_contact();
    int getting_size_of_contact();
};


#endif