#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name(""), sign(false), signGrade(150), execGrade(150) {}

Form::Form(std::string name, int signGrade, int execGrade)
    : name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();

    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), sign(other.sign), signGrade(other.signGrade), execGrade(other.execGrade) {}

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
    return execGrade;
}

int Form::getGradeS() const
{
    return signGrade;
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
    if (b.getGrade() > signGrade)
        throw GradeTooLowException();
    else
        sign = true;
}

Form::~Form() {}