#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    size_t i = 0;
    size_t found;
    std::string outfile_name;
    if(argc != 4)
    {
        std::cout<<"Program execution format: ./sed <filename> <s1> <s2>"<<std::endl;
        return 0;
    }
    std::ifstream infile(argv[1]);
    outfile_name = std::string(argv[1]) + ".replace";
    std::ofstream outfile(outfile_name.c_str());
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if(s1.empty() || s2.empty())
    {
        std::cout<<"Empty string!"<<std::endl;
        return 0;
    }
    if(!infile)
    {
        std::cout<<"File opening error!"<<std::endl;
        return 0;
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
