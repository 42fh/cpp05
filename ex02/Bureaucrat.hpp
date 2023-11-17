#pragma once
#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat&);
	Bureaucrat(const std::string, int);
	~Bureaucrat();
	
	Bureaucrat& operator=(const Bureaucrat&);
	
	const std::string	getName() const;
	int					getGrade() const;
	
	void increment();
	void decrement();
	void signForm(AForm& f, bool wasSigned);
	class GradeTooHighException: public std::exception {};
	class GradeTooLowException: public std::exception {};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);