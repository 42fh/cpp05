#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

// void TestFormOCT()
// {
// 	std::cout << "=====TestFormOCT" << std::endl;
// 	AForm F1;
// 	std::cout << F1;
// 	AForm F2("FormF2isnamedfish", 5, 10);
// 	std::cout << F2;
// 	AForm F3(F2);
// 	std::cout << F3;
// 	F1 = F3;
// 	std::cout << F1;
// }

// void TestFormExcep()
// {
// 	std::cout << "=====TestFormExcep" << std::endl;
// 	try {
// 		AForm F1("Formwithtoolowgrade", 151, 10);
// 	}
// 	catch(std::exception& e){
// 		std::cout << e.what() << std::endl;
// 	}


// 	try {
// 		AForm F2("Formwithtoolowgrade", 150, 151);
// 	}
// 	catch(std::exception& e){
// 		std::cout << e.what() << std::endl;
// 	}

// 	try {
// 		AForm F3("Formwithtoohighgrade", 0, 151);
// 	}
// 	catch(std::exception& e){
// 		std::cout << e.what() << std::endl;
// 	}

// 	try {
// 		AForm F3("Formwithtoohighgrade", 1, 0);
// 	}
// 	catch(std::exception& e){
// 		std::cout << e.what() << std::endl;
// 	}
// }

// void TestFormSigning()
// {
// 	std::cout << "=====TestFormSigning" << std::endl;
// 	AForm F1("FormF1", 10, 10);
// 	Bureaucrat B1("BuroB1", 5);
// 	F1.beSigned(B1);
// }

// void TestFormSigningErr()
// {
// 	std::cout << "=====TestFormSigning" << std::endl;
// 	AForm F1("FormF1", 10, 10);
// 	Bureaucrat B1("BuroB1", 11);
// 	try {
// 		F1.beSigned(B1);
// 	}
// 	catch(...)
// 	{
// 		std::cout << "Caught runtime exception while signing form" << std::endl;
// 	}
// }

void TestShrubberyCreationForm1()
{
	ShrubberyCreationForm s1;
	std::cout << s1.getName() << std::endl;
	
	ShrubberyCreationForm s2("TargetString");
	std::cout << s2.getName() << std::endl;

	ShrubberyCreationForm s3(s2);

	Bureaucrat B1("NameB1", 149);

	// catches the exception internally
	B1.executeForm(s2);

	// will throw exception as grade it too low
	try
	{
		s2.execute(B1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}

void TestShrubberyCreationForm2()
{
	ShrubberyCreationForm s1;
	std::cout << s1.getName() << std::endl;
	
	ShrubberyCreationForm s2("TargetString");
	std::cout << s2.getName() << std::endl;

	ShrubberyCreationForm s3(s2);

	Bureaucrat B1("NameB1", 20);

	// catches the exception internally
	B1.executeForm(s2);

	// will throw exception as grade it too low
	try
	{
		s2.execute(B1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	s2.beSigned(B1);
	B1.executeForm(s2);
	s2.execute(B1);
}

int main()
{
	TestOCF();
	// TestInit();
	// TestDecrement();
	// TestIncrement();
	// TestFormOCT();
	// TestFormExcep();
	// TestFormSigning();
	// TestFormSigningErr();

	TestShrubberyCreationForm1(); 
	TestShrubberyCreationForm2(); 
}
