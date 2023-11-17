#include "Bureaucrat.hpp"
#include "Form.hpp"

void TestOCF()
{
	Bureaucrat A;
	const Bureaucrat B("NameB", 1);
	Bureaucrat C(B);
	std::cout << "Variale A: " << A;
	std::cout << "Variale B: " << B;
	std::cout << "Variale C: " << C;
	A = B;
	std::cout << "Variale A: " << A;
}


void TestInit()
{
	try
	{
		Bureaucrat B1("NameB1", 0);
	}
	catch (std::exception & e)
	{
		std::cout << "caught (std::exception & e) exception [grade 0]" << std::endl;
	}

	try
	{
		Bureaucrat B2("NameB2", 151);
	}
	catch (std::exception & e)
	{
		std::cout << "caught (std::exception & e) exception [grade 151]" << std::endl;
	}
}

void TestDecrement()
{
	Bureaucrat B("B", 149);
	std::cout << B;

	try{
		B.decrement();
	}
	catch(...)
	{
		std::cout << "caught exception" << std::endl;
	}
	std::cout << B;

	try
	{
		/* do some stuff with bureaucrats */
		B.decrement();
	}
	catch (std::exception & e)
	{
		/* handle exception */
		std::cout << "caught (std::exception & e) exception" << std::endl;
	}
}


void TestIncrement()
{
	Bureaucrat C("C", 2);
	std::cout << C;

	try{
		C.increment();
	}
	catch(...)
	{
		std::cout << "caught exception" << std::endl;
	}
	std::cout << C;

	try
	{
		/* do some stuff with bureaucrats */
		C.increment();
	}
	catch (std::exception & e)
	{
		/* handle exception */
		std::cout << "caught (std::exception & e) exception" << std::endl;
	}
}

void TestFormOCT()
{
	std::cout << "=====TestFormOCT" << std::endl;
	Form F1;
	std::cout << F1;
	Form F2("FormF2isnamedfish", 5, 10);
	std::cout << F2;
	Form F3(F2);
	std::cout << F3;
	F1 = F3;
	std::cout << F1;
}

void TestFormExcep()
{
	std::cout << "=====TestFormExcep" << std::endl;
	try {
		Form F1("Formwithtoolowgrade", 151, 10);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}


	try {
		Form F2("Formwithtoolowgrade", 150, 151);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}

	try {
		Form F3("Formwithtoohighgrade", 0, 151);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}

	try {
		Form F3("Formwithtoohighgrade", 1, 0);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void TestFormSigning()
{
	std::cout << "=====TestFormSigning" << std::endl;
	Form F1("FormF1", 10, 10);
	Bureaucrat B1("BuroB1", 5);
	F1.beSigned(B1);
}

void TestFormSigningErr()
{
	std::cout << "=====TestFormSigning" << std::endl;
	Form F1("FormF1", 10, 10);
	Bureaucrat B1("BuroB1", 11);
	try {
		F1.beSigned(B1);
	}
	catch(...)
	{
		std::cout << "Caught runtime exception while signing form" << std::endl;
	}
}

int main()
{
	// TestOCF();
	// TestInit();
	// TestDecrement();
	// TestIncrement();
	TestFormOCT();
	TestFormExcep();
	TestFormSigning();
	TestFormSigningErr();
}
