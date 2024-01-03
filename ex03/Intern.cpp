#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern& other)
{
	(void) other;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(Intern& rhs)
{
	(void) rhs;
	return *this;
}

int foo(std::string str)
{
	(void) str;
	return 3;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm* (*fptrs[])(std::string)= {&newShrubberyCreationForm, &newRobotomyRequestForm, &newPresidentialPardonForm};
	const std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	AForm* p = NULL;
	for (int i = 0; i < 3; i++){
		if (name == names[i])
		{
			p = fptrs[i](target);
			std::cout << "Intern creates " << names[i] << std::endl;
		}
	}
	if (p == NULL)
		std::cout << "error message: form name passed as parameter doesn’t exist" << std::endl;
	return p;
}
