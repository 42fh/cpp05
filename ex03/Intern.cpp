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
	// int arr[] = {1};
	// arr[0] = 2;
	// int(*p)(int) =  &foo;
	// typedef int(*fp)(int);
	int(*arr[])(std::string)= {&foo};
	// int(*arr[])(std::string)= {&foo, &ShrubberyCreationForm::ShrubberyCreationForm};
	std::cout << arr[0]("2") << std::endl;
	(void) name;
	(void) target;

	return NULL;
}
