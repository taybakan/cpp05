#include "Form.hpp"

Form::Form(): name("unnamed"), is_signed(0), to_sign(150), to_exec(150) {}

Form::Form(std::string const _name, int const _to_sign, int const _to_exec): name(_name), is_signed(0), to_sign(_to_sign), to_exec(_to_exec)
{
	if (_to_sign > 150 || _to_exec > 150)
		throw GradeTooLowException();
	if (_to_sign < 1 || _to_exec < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &src) : name(src.getName()), is_signed(0), to_sign(src.getSignGrade()), to_exec(src.getExecGrade()) {}

Form &Form::operator=(const Form &rhs)
{
	(void) rhs;
	return (*this);
}

int Form::getSignGrade(void) const
{
	return this->to_sign;
}

int Form::getExecGrade(void) const
{
	return this->to_exec;
}

bool Form::getIsSigned(void) const
{
	return this->is_signed;
}

std::string Form::getName(void) const
{
	return this->name;
}

void Form::beSigned(const Bureaucrat &signature)
{
	if (signature.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	this->is_signed = 1;
	std::cout << signature.getName() << " signed " << this->name << "." << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const Form &src)
{
	stream << src.getName() << ", sign grade is " << src.getSignGrade() << ".";
	if (src.getIsSigned())
		stream << " It is signed.";
	else
		stream << " It is not signed.";
	return stream;
}