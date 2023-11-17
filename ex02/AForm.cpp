#include "AForm.hpp"

AForm::AForm():													name("DefaultName"),	isSigned(false),	minGradeToSign(75),						minGradeToExec(70)					{}
AForm::AForm(AForm& other):										name(other.name),		isSigned(false),	minGradeToSign(other.minGradeToSign),	minGradeToExec(other.minGradeToExec){}
AForm::AForm(std::string str, const int n, const int m):			name(str),				isSigned(false),	minGradeToSign(n),						minGradeToExec(m)
	{if(n < 1 || m < 1) throw AForm::GradeTooHighException(); else if(n > 150 || m > 150) throw AForm::GradeTooLowException();}
AForm::AForm(std::string str, bool b, const int n, const int m):	name(str),				isSigned(b),		minGradeToSign(n),						minGradeToExec(m)
	{if(n < 1 || m < 1) throw AForm::GradeTooHighException(); else if(n > 150 || m > 150) throw AForm::GradeTooLowException();}

AForm::~AForm(){}

AForm& AForm::operator=(AForm& rhs)
{
	isSigned = rhs.isSigned;
	return(*this);
}

std::string	AForm::getName() const 			{return name;}
bool		AForm::getIsSigned() const		{return isSigned;}
int			AForm::getMinGradeToSign() const	{return minGradeToSign;}
int			AForm::getMinGradeToExec() const	{return minGradeToExec;}

void AForm::beSigned(Bureaucrat& b)
{
	if (minGradeToSign < b.getGrade())
	{
		b.signForm(*this, false);
		throw AForm::GradeTooLowException();
	}
	else
	{
		isSigned = true;
		b.signForm(*this, true);
	}
}

std::ostream& operator<<(std::ostream& os, const AForm f)
{
	os << "AForm = ("
		<< "name: " << f.getName() << ", "
		<< "isSigned: " << f.getIsSigned() << ", "
		<< "minGradeToSign: " << f.getMinGradeToSign() << ", "
		<< "minGradeToExec: " << f.getMinGradeToExec() << ")"
		<< std::endl;
	return os;
}