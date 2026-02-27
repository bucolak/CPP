#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool sign;
        const int signGrade;
        const int execGrade;
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

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif