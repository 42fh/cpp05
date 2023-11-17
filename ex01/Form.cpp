#include "Form.hpp"

Form::Form():													name("DefaultName"),	isSigned(false),	minGradeToSign(75),						minGradeToExec(70)					{}
Form::Form(Form& other):										name(other.name),		isSigned(false),	minGradeToSign(other.minGradeToSign),	minGradeToExec(other.minGradeToExec){}
Form::Form(std::string str, const int n, const int m):			name(str),				isSigned(false),	minGradeToSign(n),						minGradeToExec(m)
	{if(n < 1 || m < 1) throw Form::GradeTooHighException(); else if(n > 150 || m > 150) throw Form::GradeTooLowException();}
Form::Form(std::string str, bool b, const int n, const int m):	name(str),				isSigned(b),		minGradeToSign(n),						minGradeToExec(m)
	{if(n < 1 || m < 1) throw Form::GradeTooHighException(); else if(n > 150 || m > 150) throw Form::GradeTooLowException();}

Form::~Form(){}

Form& Form::operator=(Form& rhs)
{
	isSigned = rhs.isSigned;
	return(*this);
}

std::string	Form::getName() const 			{return name;}
bool		Form::getIsSigned() const		{return isSigned;}
int			Form::getMinGradeToSign() const	{return minGradeToSign;}
int			Form::getMinGradeToExec() const	{return minGradeToExec;}

void Form::beSigned(Bureaucrat& b)
{
	if (minGradeToSign < b.getGrade())
	{
		b.signForm(*this, false);
		throw Form::GradeTooLowException();
	}
	else
	{
		isSigned = true;
		b.signForm(*this, true);
	}
}

std::ostream& operator<<(std::ostream& os, const Form f)
{
	os << "Form = ("
		<< "name: " << f.getName() << ", "
		<< "isSigned: " << f.getIsSigned() << ", "
		<< "minGradeToSign: " << f.getMinGradeToSign() << ", "
		<< "minGradeToExec: " << f.getMinGradeToExec() << ")"
		<< std::endl;
	return os;
}