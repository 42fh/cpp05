#include "Form.hpp"

Form::Form(): minGradeToSign(75), minGradeToExec(70)
{
}

Form::Form(Form& other): minGradeToSign(other.minGradeToSign), minGradeToExec(other.minGradeToExec)
{
	(void) other;
}

Form::Form(std::string str, bool b, const int n, const int m): name(str), isSigned(b), minGradeToSign(n), minGradeToExec(m)
{
	
}

Form::~Form()
{
}

Form& Form::operator=(Form& rhs)
{
	(void) rhs;
	return *this;
}

bool Form::getIsSigned()
{
	return isSigned;
}