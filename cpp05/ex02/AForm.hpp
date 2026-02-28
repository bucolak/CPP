#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        bool sign;
        const int s_grade;
        const int e_grade;
    public:
        AForm();
        AForm(std::string name, int s_grade, int e_grade);
        AForm(const AForm &other);
        AForm& operator=(const AForm& other);
        ~AForm();

        std::string getName() const;
        bool getSign() const;
        int getGradeS() const;
        int getGradeE() const;
        void beSigned(const Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;
        void executeCheck(Bureaucrat const & executor) const;

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
        class FormNotSignedException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif