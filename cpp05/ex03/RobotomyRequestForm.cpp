#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    executeCheck(executor);
    std::cout<<"ZZZZZZT.....Drilling noises..."<<std::endl;
    if(std::rand() % 2 == 0)
        std::cout<<target<<" robotomized successfully"<<std::endl;
    else
        std::cout<<target<<" Robotomy failed"<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}