#include "PhoneBook.hpp"

int main()
{
    PhoneBook phone_book;
    std::string first_input;

    std::cout<<"Welcome to Menu!"<<std::endl;
    std::cout<<"Please, Enter a valid input (ADD, SEARCH, EXIT)!"<<std::endl;
    while(1)
    {
        std::cout<<"> ";
        if(!std::getline(std::cin, first_input))
            break;
        if(first_input == "ADD")
        {
            phone_book.add_contact();
        }
        else if(first_input == "SEARCH")
        {
            if(phone_book.getting_size_of_contact() != 0)
                phone_book.search_contact();
            else
                std::cout<<"Please, Add a person before Searching!"<<std::endl;
        }
        else if(first_input == "EXIT")
            break;
        else
            std::cout<<"Please, Enter a valid input (ADD, SEARCH, EXIT)!"<<std::endl;
    }
    return 0;
}
