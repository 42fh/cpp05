#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): name("DefaultName"), grade(75){}
Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade){}

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

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	// the following line would give a compile time error as name is const
	// this->name = rhs.name;
	this->grade = rhs.grade;
	return *this;
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

void Bureaucrat::signForm(AForm& f, bool wasSigned)
{
	if (wasSigned)
		std::cout << name << " signed " << f.getName() << std::endl;
	else
		std::cout << name << " couldn’t sign " << f.getName() << " because of low grade" << std::endl;
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << "executed" << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error message: " << this->getName() << "couldn't execute" << form.getName() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade: " << b.getGrade() << std::endl;
	return out;
}