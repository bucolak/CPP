#include "AForm.hpp"

AForm::AForm() : name(""), sign(false), s_grade(150), e_grade(150) {}

AForm::AForm(std::string name, int s_grade, int e_grade)
    : name(name), sign(false), s_grade(s_grade), e_grade(e_grade)
{
	if (s_grade < 1 || e_grade < 1)
        throw GradeTooHighException();

    if (s_grade > 150 || e_grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), sign(other.sign), s_grade(other.s_grade), e_grade(other.e_grade) {}

AForm& AForm::operator=(const AForm& other)
{
	this->sign = other.sign;
	return *this;
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getSign() const
{
    return sign;
}

int AForm::getGradeE() const
{
    return e_grade;
}

int AForm::getGradeS() const
{
    return s_grade;
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
	out<<"AForm "<<obj.getName()<<", sign grade "<<obj.getGradeS()
        <<", exec grade "<<obj.getGradeE()<<", "<<(obj.getSign() ? "signed" : "not signed");
	return out;
}

void AForm::executeCheck(Bureaucrat const & executor) const
{
    if(!getSign())
        throw GradeTooLowException();
    if(executor.getGrade() > e_grade)
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Too High Value";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Too Low Value";
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > s_grade)
        throw GradeTooLowException();
    else
        sign = true;
}

AForm::~AForm() {}