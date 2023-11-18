#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShCrDefautName", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other): AForm(other.getName(), 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& rhs)
{
	this->AForm::operator=(rhs);
	return *this;
}

void ShrubberyCreationForm::action() const
{
	const std::string filename(this->getName() + "_shrubbery");
	std::ofstream outfile(filename.c_str());
	if (outfile.fail())
		std::cout << "Failed to open File" << std::endl;
	else
		outfile
			<<	"                          " << std::endl
			<<	"   @@@   @@@    @@ @@@    " << std::endl
			<<	"  @@@@@ @@@@@  @@@@@@@@   " << std::endl
			<<	"  @@@@@ @@@@@  @@@@@@@@   " << std::endl
			<<	"   @@@   @@@    @@ @@@    " << std::endl
			<<	"    |     |      |  |     " << std::endl
			<<	"    |     |      |  |     " << std::endl
			<<	"--------------------------" << std::endl;
	outfile.close();
}