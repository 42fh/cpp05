#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RoReDefautName", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other): AForm(other.getName(), 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& rhs)
{
	this->AForm::operator=(rhs);
	return *this;
}

void RobotomyRequestForm::action() const
{
	std::cout << "*DRILLING NOISE*" << std::endl;
	int r = rand() % 2;
	if (r == 0)
		std::cout << this->getName() << " has been robotomized successfull" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}

AForm* newRobotomyRequestForm(std::string str)
{
	return(new RobotomyRequestForm(str));
}