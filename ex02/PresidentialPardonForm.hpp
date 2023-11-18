#pragma once
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm&);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(PresidentialPardonForm&);
	
	void action() const;
};
