#pragma once
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern&);
	~Intern();
	Intern& operator=(Intern&);

	AForm* makeForm(std::string name, std::string target);
};
