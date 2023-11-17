#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			minGradeToSign;
	const int			minGradeToExec;

public:
	Form();
	Form(Form&);
	Form(std::string, const int, const int);
	Form(std::string, bool, const int, const int);
	
	~Form();
	Form& operator=(Form&);

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getMinGradeToSign() const;
	int			getMinGradeToExec() const;

	void beSigned(Bureaucrat&);

	class GradeTooHighException:	public std::exception{};
	class GradeTooLowException:		public std::exception{};
};

std::ostream& operator<<(std::ostream&, Form);