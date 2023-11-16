#include "Bureaucrat.hpp"

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

int main()
{
	TestOCF();
	TestInit();
	TestDecrement();
	TestIncrement();
}
