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
	std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	AForm* p;
	for (int i = 0; i < 3; i++){
		if (name == names[i])
		{
			p = fptrs[i](target);
			std::cout << name << "++" << i << std::endl;
		}
	}

	return p;
}
