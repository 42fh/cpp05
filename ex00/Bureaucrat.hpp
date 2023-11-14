#pragma once
#include <string>
#include <iostream>

class Bureaucrat
{
private:
	std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat&);
	Bureaucrat(const std::string, int);
	~Bureaucrat();
	Bureaucrat& operator=(Bureaucrat&);
	const std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	class GradeTooHighException: public std::exception {};
	class GradeTooLowException: public std::exception {};
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& b);