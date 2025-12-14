#include "PhoneBook.hpp"

void PhoneBook::add_contact()
{
    std::string input;
    int flag = 0;

    index_of_contacts = size_of_contact % 8;

    // --------------------------------------------
    while(flag!=1)
    {
        std::cout<<"Enter the First Name: ";
        std::getline(std::cin, input);
        for(int i = 0;input[i];i++)
        {
            if(!std::isspace(input[i]))
                flag = 1;
        }
        if(flag == 1)
            contact[index_of_contacts].setting_first_name(input);
    }
    flag = 0;
    // --------------------------------------------
    while(flag!=1)
    {
        std::cout<<"Enter the Last Name: ";
        std::getline(std::cin, input);
        for(int i = 0;input[i];i++)
        {
            if(!std::isspace(input[i]))
                flag = 1;
        }
        if(flag == 1)
            contact[index_of_contacts].setting_last_name(input);
    }
    flag = 0;
    // --------------------------------------------
    while(flag!=1)
    {
        std::cout<<"Enter the Nick Name: ";
        std::getline(std::cin, input);
        for(int i = 0;input[i];i++)
        {
            if(!std::isspace(input[i]))
                flag = 1;
        }
        if(flag == 1)
            contact[index_of_contacts].setting_nick_name(input);
    }
    flag = 0;
    // --------------------------------------------
    while(flag!=1)
    {
        std::cout<<"Enter the Phone Number: ";
        std::getline(std::cin, input);
        for(int i = 0;input[i];i++)
        {
            if(!std::isspace(input[i]))
                flag = 1;
        }
        if(flag == 1)
            contact[index_of_contacts].setting_phone_number(input);
    }
    flag = 0;
    // --------------------------------------------
    while(flag!=1)
    {
        std::cout<<"Enter the Darkest String: ";
        std::getline(std::cin, input);
        for(int i = 0;input[i];i++)
        {
            if(!std::isspace(input[i]))
                flag = 1;
        }
        if(flag == 1)
            contact[index_of_contacts].setting_darkest_string(input);
    }
    size_of_contact++;
}

int is_numeric(std::string temporary_str)
{
    int i = 0;
    if(temporary_str.empty())
        return 0;

    if(temporary_str[i] =='-' || temporary_str[i] =='+')
        i++;
    for(;temporary_str[i];i++)
    {
        if(!std::isdigit(temporary_str[i]))
            return 0; // numeric değil
    }
    return 1; //numeric
}

void PhoneBook::search_contact()
{
    int input=-1;
    std::string temporary_str;
    
    std::cout<<"---------------------------------------------"<<std::endl;
    std::cout<<"|"<<std::setw(10)<<"INDEX"
            <<"|"<<std::setw(10)<<"FIRST NAME"
            <<"|"<<std::setw(10)<<"LAST NAME"
            <<"|"<<std::setw(10)<<"NICK NAME"
            <<"|"<<std::endl;
    std::cout<<"---------------------------------------------"<<std::endl;

    for(int i = 0;i < 8;i++)
    {
		if(!contact[i].getting_first_name().empty())
		{
			std::cout<<"|"<<std::setw(10)<<i;
			if(contact[i].getting_first_name().length()>10)
				std::cout<<"|"<<std::setw(10)<<contact[i].getting_first_name().substr(0,9)<<".";
			else
				std::cout<<"|"<<std::setw(10)<<contact[i].getting_first_name();
		
			if(contact[i].getting_last_name().length()>10)
				std::cout<<"|"<<std::setw(10)<<contact[i].getting_last_name().substr(0,9)<<".";
			else
				std::cout<<"|"<<std::setw(10)<<contact[i].getting_last_name();
			
			if(contact[i].getting_nick_name().length()>10)
				std::cout<<"|"<<std::setw(10)<<contact[i].getting_nick_name().substr(0,9)<<"."<<"|"<<std::endl;
			else
				std::cout<<"|"<<std::setw(10)<<contact[i].getting_nick_name()<<"|"<<std::endl;
		}
		else
			break;
        std::cout<<"---------------------------------------------"<<std::endl;
    }

    while(!(input >= 0 && input<8))
    {
        std::cout<<"Please, Enter the Index : ";
        
        if(!std::getline(std::cin, temporary_str))
            exit(0);
        while(!is_numeric(temporary_str))
        {
            std::cout<<"Please, Enter the Index : ";
            std::getline(std::cin, temporary_str);
        }
        input = std::atoi(temporary_str.c_str());
                
        if(input>=0 && input<8)
        {
            if(!contact[input].getting_first_name().empty())
            {
                std::cout<<"First Name: "<<contact[input].getting_first_name()<<std::endl;
                std::cout<<"Last Name: "<<contact[input].getting_last_name()<<std::endl;
                std::cout<<"Nick Name: "<<contact[input].getting_nick_name()<<std::endl;
                std::cout<<"Phone Number: "<<contact[input].getting_phone_number()<<std::endl;
                std::cout<<"Darkest Secret: "<<contact[input].getting_darkest_string()<<std::endl;
            }
            else
            {
                std::cout<<"There is no one with this index!"<<std::endl;
                input = -1;
            }
        }     
        else
            std::cout<<"Please, Enter the correct index!"<<std::endl;
    }
}

int main()
{
    PhoneBook phone_book;
    std::string first_input;

    std::cout<<"Welcome to Menu!"<<std::endl;
    while(1)
    {
        std::cout<<"> ";
        if(!std::getline(std::cin, first_input))
            exit(0);
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
            exit(0);
        else
            std::cout<<"Please, Enter a valid input (ADD, SEARCH, EXIT)!"<<std::endl;
    }
}