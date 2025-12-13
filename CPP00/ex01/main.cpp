#include "PhoneBook.hpp"

void PhoneBook::add_contact()
{
    PhoneBook phone_book;
    std::string input;

    if(size_of_contact == 8)
        size_of_contact = oldest_contact_size;

    std::cout<<"Enter the First Name: ";
    std::getline(std::cin, input);
    phone_book.contact[size_of_contact].setting_first_name(input);

    std::cout<<"Enter the Last Name: ";
    std::getline(std::cin, input);
    phone_book.contact[size_of_contact].setting_last_name(input);

    std::cout<<"Enter the Nick Name: ";
    std::getline(std::cin, input);
    phone_book.contact[size_of_contact].setting_nick_name(input);

    std::cout<<"Enter the Phone Number: ";
    std::getline(std::cin, input);
    phone_book.contact[size_of_contact].setting_phone_number(input);

    std::cout<<"Enter the Darkest String: ";
    std::getline(std::cin, input);
    phone_book.contact[size_of_contact].setting_darkest_string(input);

    oldest_contact_size = size_of_contact;

    size_of_contact++;
}

void PhoneBook::search_contact()
{
    int input=-1;
    
    std::cout<<"--------------------------------"<<std::endl;
    std::cout<<"|"<<std::setw(10)<<"INDEX"
            <<"|"<<std::setw(10)<<"FIRST NAME"
            <<"|"<<std::setw(10)<<"LAST NAME"
            <<"|"<<std::setw(10)<<"NICK NAME"
            <<"|"<<std::endl;
    
    for(int i = 0;i<size_of_contact;i++)
    {
        std::cout<<"|"<<std::setw(10)<<i;
        if(contact[i].getting_first_name().length()>10)
            std::cout<<"|"<<std::setw(10)<<contact[i].getting_first_name().substr(0,9)<<".";

        std::cout<<"|"<<std::setw(10)<<i
                <<"|"<<std::setw(10)<<contact[i].getting_first_name()
                <<"|"<<std::setw(10)<<contact[i].getting_last_name()
                <<"|"<<std::setw(10)<<contact[i].getting_nick_name()
                <<"|"<<std::endl;
    }

    while(!(input >= 0 && input<8))
    {
        std::cout<<"Please, Enter the Index : ";
        std::cin>>input;
        std::cout<<std::endl;
        
        std::cout<<"|"<<std::setw(10)<<contact[input].getting_first_name()
                <<"|"<<std::setw(10)<<contact[input].getting_last_name()
                <<"|"<<std::setw(10)<<contact[input].getting_nick_name()
                <<"|"<<std::setw(10)<<contact[input].getting_phone_number()
                <<"|"<<std::setw(10)<<contact[input].getting_darkest_string()
                <<"|"<<std::endl;
    }
}

int main()
{
    PhoneBook phone_book;
    std::string first_input;
    std::string current_input;

    while(1)
    {
        std::cout<<"Welcome to Menu!"<<std::endl;
        std::getline(std::cin, first_input);
        if(first_input == "ADD")
        {
            phone_book.add_contact();
        }
        else if(first_input == "SEARCH")
        {
            phone_book.search_contact();
        }
        else if(first_input == "EXIT")
        {
            // exit(0);
        }
        else
        {

        }
    }
}