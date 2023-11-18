#pragma once
#include <fstream>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm&);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(RobotomyRequestForm&);
	
	void action() const;
};

