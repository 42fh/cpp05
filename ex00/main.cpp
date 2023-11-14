#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat A;
	std::cout << A;
	Bureaucrat B("A", 150);
	std::cout << B;
	try{
		B.decrement();
	}
	catch(...)
	{
		std::cout << "caught exception" << std::endl;
	}

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
