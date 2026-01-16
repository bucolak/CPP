#include "Sed.hpp"

Sed::Sed(std::string s1, std::string s2, std::string filename)
{
    this->s1 = s1;
    this->s2 = s2;
    this->filename = filename;
}

void Sed::replace()
{
    size_t i = 0;
    size_t found;
    std::string outfile_name;

    std::ifstream infile(filename.c_str());
    outfile_name = filename + ".replace";
    std::ofstream outfile(outfile_name.c_str());

    if(s1.empty() || s2.empty())
    {
        std::cout<<"Empty string!"<<std::endl;
        return ;
    }

    if(!infile || !outfile)
    {
        std::cout<<"File opening error!"<<std::endl;
        return ;
    }

    std::string line(
        (std::istreambuf_iterator<char>(infile)),
        std::istreambuf_iterator<char>()
    );

    while(i < line.size())
    {
        found = line.find(s1, i);
        if(found != std::string::npos)
        {
            for(size_t j = i; j < found; j++)
                outfile << line[j];
            outfile << s2;
            i = s1.length() + found;
        }
        else
        {
            for(size_t j = i; j < line.size(); j++)
                outfile << line[j];
            break;
        }
    }
}
