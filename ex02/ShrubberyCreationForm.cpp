#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("empty")
{
	std::cout << "Shrubbery Target Constructor Call" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm", 145, 137), target(_target)
{
	std::cout << "Shrubbery Target Constructor Call" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : target("copy" + src.getTarget())
{
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	(void) rhs;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &signature) const
{
	if (this->getIsSigned() == 0)
		throw SignatureException();
	if (signature.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::ofstream pot(this->target + "_shrubbery");
	pot << "       /\\       " << std::endl;
	pot << "      /\\*\\     " << std::endl;
	pot << "     /\\O\\*\\     " << std::endl;
	pot << "    /*/\\/\\/\\    " << std::endl;
	pot << "   /\\O\\/\\*\\/\\   " << std::endl;
	pot << "  /\\*\\/\\*\\/\\/\\  " << std::endl;
	pot << " /\\O\\/\\/*/\\/O/\\ " << std::endl;
	pot << "       ||       " << std::endl;
	pot << "       ||       " << std::endl;
	pot << "       ||       " << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Shrubbery Destructor." << std::endl;
}