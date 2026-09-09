#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : rate(other.rate) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if(this != &other)
    {
        this->rate = other.rate;
    }
    return *this;
}

bool isNumber(std::string str)
{
    size_t i = 0;
    while(i < str.size())
    {
        if(!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

void control_of_date(std::string date)
{
    int c = std::count(date.begin(), date.end(), '-');
    if(c!=2)
        throw std::runtime_error("Error: bad input => " + date);
    size_t f = date.find("-");
    std::string year = date.substr(0, f);
    if(year.size() !=4 || !isNumber(year))
        throw std::runtime_error("Error: bad input => " + date);
    size_t s = date.find("-",f+1);
    std::string month = date.substr(f+1, s-f-1);
    if((!isNumber(month)) || !(std::atoi(month.c_str()) >=1 && std::atoi(month.c_str()) <=12))
        throw std::runtime_error("Error: bad input => " + date);
    std::string day = date.substr(s+1, date.size()-s);
    if(!isNumber(day) || !(std::atoi(day.c_str())>=1 && std::atoi(day.c_str())<=31))
        throw std::runtime_error("Error: bad input => " + date);
}

void control_of_val(std::string val)
{
    int dot = 0;
    int digit = 0;
    if(val.empty())
        throw std::runtime_error("Error: no value in Input File.");
    if(val[0] == '-')
        throw std::runtime_error("Error: not a positive number.");
    for(size_t i = 0; i < val.size(); i++)
    {
        if((i != 0) && (i != val.size()-1) && val[i] == '.')
        {
            dot++;
            continue;
        }
        if(!std::isdigit(val[i]) || dot > 1)
        throw std::runtime_error("Error: invalid value.");
        digit++;
    }
    if(digit < 1)
        throw std::runtime_error("Error: invalid value.");
    float num = std::atof(val.c_str());
    if(num > 1000)
        throw std::runtime_error("Error: too large a number.");
}

void BitcoinExchange::print_bitcoin(std::string inputFileName)
{
    std::ifstream dbFile("data.csv");
    if(!dbFile)
        throw std::runtime_error("Error: could not open file.");
    std::string line;

    std::getline(dbFile, line);
    while(std::getline(dbFile, line))
    {
        size_t i = line.find(",");
        std::string key = line.substr(0, i);
        float val = std::atof(line.substr(i+1, line.size()-i+1).c_str());
        rate[key] = val;
    }
    
    std::ifstream inputFile(inputFileName.c_str());
    std::map<std::string, float>::iterator it;
    if(!inputFile)
        throw std::runtime_error("Error: could not open file.");
    std::getline(inputFile, line);
    while(std::getline(inputFile, line))
    {
        try
        {
            size_t i = line.find("|");
            if(i == std::string::npos)
                throw std::runtime_error("Error: bad input => " + line);
            std::string key = line.substr(0, i-1);
            control_of_date(key);
            it = rate.lower_bound(key);
            if(it == rate.end())
                --it;
            if(it->first != key)
            {
                if(it == rate.begin())
                    throw std::runtime_error("Error: no found date.");
            }
            std::string val = line.substr(i+2, line.size()-i+1);
            control_of_val(val);
            float newVal = it->second * std::atof(val.c_str());
            std::cout<<key<<" => "<<val<<" = "<<newVal<<std::endl;
        }
        catch (std::exception &e)
        {
            std::cout<<e.what()<<std::endl;
        }
    }
}

BitcoinExchange::~BitcoinExchange() {}