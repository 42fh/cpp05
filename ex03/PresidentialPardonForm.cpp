#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PrPaDefautName", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other): AForm(other.getName(), 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& rhs)
{
	this->AForm::operator=(rhs);
	return *this;
}

void PresidentialPardonForm::action() const
{
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

AForm* newPresidentialPardonForm(std::string str)
{
	return(new PresidentialPardonForm(str));
}