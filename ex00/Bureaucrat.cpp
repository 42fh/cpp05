#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("DefaultName"), grade(75){}
Bureaucrat::Bureaucrat(Bureaucrat& other): name(other.name), grade(other.grade){}

Bureaucrat::Bureaucrat(const std::string str, int i): name(str), grade(i)
{
	if (i > 150)
		throw Bureaucrat::GradeTooLowException();	
	else if (i < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& rhs)
{
	return rhs;
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
	if (grade > 1)
		grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement()
{
	if (grade < 150)
		grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade: " << b.getGrade() << std::endl;
	return out;
}