#pragma once
#include <string>

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int minGradeToSign;
	const int minGradeToExec;
public:
	Form();
	Form(Form&);
	Form(std::string, bool, const int, const int);
	~Form();
	Form& operator=(Form&);

	bool getIsSigned();

	class GradeTooHighException: public std::exception{};
	class GradeTooLowException: public std::exception{};
};