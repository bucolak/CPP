#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool sign;
        const int s_grade;
        const int e_grade;
    public:
        Form();
        Form(std::string name, int s_grade, int e_grade);
        Form(const Form &other);
        Form& operator=(const Form& other);
        ~Form();

        std::string getName() const;
        bool getSign() const;
        int getGradeS() const;
        int getGradeE() const;
        void beSigned(const Bureaucrat &b);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif