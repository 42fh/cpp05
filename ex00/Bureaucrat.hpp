#pragma once
#include <string>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat&);
	~Bureaucrat();
	Bureaucrat& operator=(Bureaucrat&);
	const std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
};

