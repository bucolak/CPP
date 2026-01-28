#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    size_of_contact = 0;
}

int PhoneBook::getting_size_of_contact()
{
    return size_of_contact;
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
        if(!is_valid_i(input) || !is_full_space(input))
            continue;
        contact[index_of_contacts].setting_first_name(input);
        break;
    }	
    while(1)
    {
        std::cout<<"Enter the Last Name: ";
        if(!std::getline(std::cin, input))
            return;
        if(!is_valid_i(input) || !is_full_space(input))
            continue;
        contact[index_of_contacts].setting_last_name(input);
        break;
    }
    while(1)
    {
        std::cout<<"Enter the Nick Name: ";
        if(!std::getline(std::cin, input))
            return;
        if(!is_valid_i(input) || !is_full_space(input))
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
        if(!is_valid_i(input) || !is_full_space(input))
            continue;
        contact[index_of_contacts].setting_darkest_string(input);
        break;
    }
    size_of_contact++;
}

void PhoneBook::search_contact()
{
    int input=-1;
    std::string temporary_str;
    int temporary_id;
    std::string str;
    
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
			std::cout<<"|"<<std::setw(10)<<i+1;
			if(contact[i].getting_first_name().length()>10)
                std::cout<<"|"<<contact[i].getting_first_name().substr(0,9)<<".";
			else
				std::cout<<"|"<<std::setw(10)<<contact[i].getting_first_name();
		
			if(contact[i].getting_last_name().length()>10)
				std::cout<<"|"<<contact[i].getting_last_name().substr(0,9)<<".";
			else
				std::cout<<"|"<<std::setw(10)<<contact[i].getting_last_name();
			
			if(contact[i].getting_nick_name().length()>10)
				std::cout<<"|"<<contact[i].getting_nick_name().substr(0,9)<<"."<<"|"<<std::endl;
			else
				std::cout<<"|"<<std::setw(10)<<contact[i].getting_nick_name()<<"|"<<std::endl;
		}
		else
			break;
        std::cout<<"---------------------------------------------"<<std::endl;
    }

    while(!(input >= 1 && input<=8))
    {
        std::cout<<"Please, Enter the Index : ";
        
        if(!std::getline(std::cin, temporary_str))
            return;
        while(!is_numeric(temporary_str))
        {
            std::cout<<"Please, Enter the Index : ";
            if(!std::getline(std::cin, temporary_str))
                return;
        }
        input = std::atoi(temporary_str.c_str());

        if(input>=1 && input<=8)
        {
            temporary_id = input -1;
            if(!contact[temporary_id].getting_first_name().empty())
            {
                std::cout<<"First Name: "<<contact[temporary_id].getting_first_name()<<std::endl;
                std::cout<<"Last Name: "<<contact[temporary_id].getting_last_name()<<std::endl;
                std::cout<<"Nick Name: "<<contact[temporary_id].getting_nick_name()<<std::endl;
                std::cout<<"Phone Number: "<<contact[temporary_id].getting_phone_number()<<std::endl;
                std::cout<<"Darkest Secret: "<<contact[temporary_id].getting_darkest_string()<<std::endl;
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
