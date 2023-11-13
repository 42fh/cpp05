#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat& other)
{
	(void) other;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& rhs)
{
	(void) rhs;
}

const std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::increment()
{

}

void Bureaucrat::decrement()
{

}