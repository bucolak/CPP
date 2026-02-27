#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : name(name), grade(grade) 
{
	if(grade < 1)
		throw GradeTooHighException();
	if(grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	this->grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	this->grade = other.grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName()<<", bureaucrat grade "<<obj.getGrade()<<".";
	return out;
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << name << " signed " << f.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout<<name<<" couldn't sign "<<f.getName()
              <<" because "<<e.what()<<std::endl;
	}
}

void Bureaucrat::decGrade(int x)
{
	if((grade + x) > 150)
		throw GradeTooLowException();
	grade += x;
}

void Bureaucrat::incGrade(int x)
{
	if((grade - x) < 1)
		throw GradeTooHighException();
	grade -= x;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Too High Value";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Too Low Value";
}

Bureaucrat::~Bureaucrat() {}