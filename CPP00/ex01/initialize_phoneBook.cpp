#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    size_of_contact = 0;
}

int PhoneBook::getting_size_of_contact()
{
    return size_of_contact;
}

PhoneBook::~PhoneBook()
{
    std::cout<<"PhoneBook Destructor executed!"<<std::endl;
}