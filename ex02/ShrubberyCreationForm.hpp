#pragma once
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm&);
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(ShrubberyCreationForm&);
	
	void action() const;
};

