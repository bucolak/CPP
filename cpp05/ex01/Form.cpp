#include "Form.hpp"

Form::Form() : name(""), sign(false), s_grade(150), e_grade(150) {}

Form::Form(std::string name, int s_grade, int e_grade)
    : name(name), sign(false), s_grade(s_grade), e_grade(e_grade)
{
	if (s_grade < 1 || e_grade < 1)
        throw GradeTooHighException();

    if (s_grade > 150 || e_grade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), sign(other.sign), s_grade(other.s_grade), e_grade(other.e_grade) {}

Form& Form::operator=(const Form& other)
{
	this->sign = other.sign;
	return *this;
}

std::string Form::getName() const
{
    return name;
}

bool Form::getSign() const
{
    return sign;
}

int Form::getGradeE() const
{
    return e_grade;
}

int Form::getGradeS() const
{
    return s_grade;
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
	out<<"Form "<<obj.getName()<<", sign grade "<<obj.getGradeS()
        <<", exec grade "<<obj.getGradeE()<<", "<<(obj.getSign() ? "signed" : "not signed");
	return out;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Too High Value";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Too Low Value";
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > s_grade)
        throw GradeTooLowException();
    else
        sign = true;
}

Form::~Form() {}