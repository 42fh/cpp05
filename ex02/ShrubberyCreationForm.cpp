#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShCrDefautName", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other): AForm(other.getName(), 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& rhs)
{
	this->AForm::operator=(rhs);
	return *this;
}

void ShrubberyCreationForm::action() const
{
	std::cout << "ShrubberyCreationForm *Action*" << std::endl;
}