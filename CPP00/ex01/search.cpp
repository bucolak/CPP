#include "PhoneBook.hpp"

static int is_numeric(std::string temporary_str)
{
    int i = 0;
    if(temporary_str.empty())
        return 0;

    if(temporary_str[i] =='-' || temporary_str[i] =='+')
        i++;
    for(;temporary_str[i];i++)
    {
        if(!std::isdigit(temporary_str[i]))
            return 0;
    }
    return 1;
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
