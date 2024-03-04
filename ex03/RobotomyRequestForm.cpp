#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("unnamed")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequestForm", 72, 45), target(_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm("RobotomyRequestForm", 72, 45), target("copy_" + src.getTarget())
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	(void)rhs;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &signature) const
{
	if (signature.getGrade() > this->getExecGrade())
		throw SignatureException();
	std::cout << "* DRILL DRILL DRILL *" << std::endl;
	if (std::rand() % 2)
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy has failed." << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return this->target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}
