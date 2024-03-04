#include "AForm.hpp"

AForm::AForm(): name("unnamed"), is_signed(0), to_sign(150), to_exec(150) {}

AForm::AForm(std::string const _name, int const _to_sign, int const _to_exec): name(_name), is_signed(0), to_sign(_to_sign), to_exec(_to_exec)
{
	if (_to_sign > 150 || _to_exec > 150)
		throw GradeTooLowException();
	if (_to_sign < 1 || _to_exec < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &src) : name(src.getName()), is_signed(0), to_sign(src.getSignGrade()), to_exec(src.getExecGrade()) {}

AForm &AForm::operator=(const AForm &rhs)
{
	(void) rhs;
	return (*this);
}

int AForm::getSignGrade(void) const
{
	return this->to_sign;
}

int AForm::getExecGrade(void) const
{
	return this->to_exec;
}

bool AForm::getIsSigned(void) const
{
	return this->is_signed;
}

std::string AForm::getName(void) const
{
	return this->name;
}

void AForm::beSigned(const Bureaucrat &signature)
{
	if (signature.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	this->is_signed = 1;
	std::cout << signature.getName() << " signed " << this->name << "." << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm Destructor Call" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const AForm &src)
{
	stream << src.getName() << ", sign grade is " << src.getSignGrade() << ".";
	if (src.getIsSigned())
		stream << " It is signed.";
	else
		stream << " It is not signed.";
	return stream;
}