#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string	name;
	bool				isSigned;
	const int			minGradeToSign;
	const int			minGradeToExec;

public:
	AForm();
	AForm(AForm&);
	AForm(std::string, const int, const int);
	AForm(std::string, bool, const int, const int);
	
	~AForm();
	AForm& operator=(AForm&);

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getMinGradeToSign() const;
	int			getMinGradeToExec() const;

	void beSigned(Bureaucrat&);

	class GradeTooHighException:	public std::exception{};
	class GradeTooLowException:		public std::exception{};
};

std::ostream& operator<<(std::ostream&, AForm);