#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class Sed{
    
    private:
        std::string s1;
        std::string s2;
        std::string filename;
    public:
        Sed(std::string s1, std::string s2, std::string filename);
        void replace();
};

#endif