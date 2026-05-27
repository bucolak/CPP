#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void int_control(std::string argv)
{
    size_t i = 0;
    if(argv[0] == '-' || argv[0] == '+')
        i++;
    for(; i < argv.size(); i++)
    {
        if(!std::isdigit(argv[i]))
        {
            std::cout << "Invalid Input! Usage: <program> value" << std::endl;
            return ;
        }
    }
    long iv = std::atol(argv.c_str());
    std::cout << "char : ";
    if(iv < 0 || iv > 127)
        std::cout << "impossible" << std::endl;
    else if(std::isprint(static_cast<char>(iv)))
        std::cout << "'" << static_cast<char>(iv) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int : ";
    if(iv > std::numeric_limits<int>::max()
        || iv < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(iv) << std::endl;
    float fv = static_cast<float>(iv);
    double dv = static_cast<double>(iv);
    std::cout << "float : " << fv;
    if(fv == static_cast<int>(fv))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "double : " << dv;
    if(dv == static_cast<int>(dv))
        std::cout << ".0";
    std::cout << std::endl;
}

void char_control(std::string argv)
{
    char cv = argv[0];
    int iv = static_cast<int>(cv);
    float fv = static_cast<float>(cv);
    double dv = static_cast<double>(cv);

    std::cout << "char : '" << cv << "'" << std::endl;
    std::cout << "int : " << iv << std::endl;
    std::cout << "float : " << fv;
    if(fv == static_cast<int>(fv))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "double : " << dv;
    if(dv == static_cast<int>(dv))
        std::cout << ".0";
    std::cout << std::endl;
}

void double_control(std::string argv)
{
    int count_dot = 0;
    int count_digit = 0;
    size_t i = 0;

    if(argv[0] == '-' || argv[0] == '+')
        i++;
    for(; i < argv.size(); i++)
    {
        if(!std::isdigit(argv[i]))
        {
            if(argv[i] == '.')
            {
                count_dot++;
                continue;
            }
            else
            {
                std::cout << "Invalid Input! Usage: <program> value" << std::endl;
                return ;
            }
        }
        count_digit++;
    }
    if(count_dot != 1 || count_digit < 1)
    {
        std::cout << "Invalid Input! Usage: <program> value" << std::endl;
        return ;
    }

    double dv = std::atof(argv.c_str());
    std::cout << "char : ";
    if(dv < 0 || dv > 127)
        std::cout << "impossible" << std::endl;
    else if(std::isprint(static_cast<char>(dv)))
        std::cout << "'" << static_cast<char>(dv) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int : ";
    if(dv > std::numeric_limits<int>::max()
        || dv < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(dv) << std::endl;
    float fv = static_cast<float>(dv);
    std::cout << "float : " << fv;
    if(fv == static_cast<int>(fv))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "double : " << dv;
    if(dv == static_cast<int>(dv))
        std::cout << ".0";
    std::cout << std::endl;
}

void float_control(std::string argv)
{
    int count_dot = 0;
    int count_digit = 0;
    size_t i = 0;
    if(argv[0] == '-' || argv[0] =='+')
        i++;
    for(;i < argv.size() - 1; i++)
    {
        if(!std::isdigit(argv[i]))
        {
            if(argv[i] == '.')
            {
                count_dot++;
                continue;
            }
            else
            {
                std::cout<<"Invalid Input! Usage: <program> value"<<std::endl;
                return ;
            }
        }
        count_digit++;
    }
    if(count_dot != 1 || count_digit < 1)
    {
        std::cout<<"Invalid Input! Usage: <program> value"<<std::endl;
        return ;
    }
    float fv = std::atof(argv.c_str());
    std::cout << "char : ";
    if(fv < 0 || fv > 127)
        std::cout << "impossible" << std::endl;
    else if(std::isprint(static_cast<char>(fv)))
        std::cout << "'" << static_cast<char>(fv) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int : ";
    if(fv > std::numeric_limits<int>::max()
        || fv < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(fv) << std::endl;
    double dv = static_cast<double>(fv);
    std::cout << "float : " << fv;
    if(fv == static_cast<int>(fv))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "double : " << dv;
    if(dv == static_cast<int>(dv))
        std::cout << ".0";
    std::cout << std::endl;
}

void pseudo_control(std::string argv)
{
    std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;

    if(argv == "nanf" || argv == "nan")
    {
        std::cout << "float : nanf" << std::endl;
        std::cout << "double : nan" << std::endl;
    }
    else if(argv == "+inff" || argv == "+inf")
    {
        std::cout << "float : +inff" << std::endl;
        std::cout << "double : +inf" << std::endl;
    }
    else if(argv == "-inff" || argv == "-inf")
    {
        std::cout << "float : -inff" << std::endl;
        std::cout << "double : -inf" << std::endl;
    }
}

void ScalarConverter::convert(std::string argv)
{
    if(argv.empty())
    {
        std::cout<<"Invalid Input! Usage: <program> value"<<std::endl;
        return ;
    }
    if(argv == "nanf" || argv == "+inff" || argv == "-inff" || argv == "nan" || argv == "+inf" || argv == "-inf")
        pseudo_control(argv);
    else if(argv[argv.size() - 1] == 'f')
        float_control(argv);
    else if(argv.find('.') != std::string::npos)
        double_control(argv);
    else if(argv.size() == 1 && !std::isdigit(argv[0]))
        char_control(argv);
    else
        int_control(argv);
}