#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("unnamedBureaucrat"), grade(150){}

Bureaucrat::Bureaucrat(std::string const _name, int _grade) : name(_name), grade(_grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat " << this->getName() << " was created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.getName()), grade(src.getGrade()) {}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	this->grade = rhs.getGrade();
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return(grade);
}

void Bureaucrat::increment(void)
{
	if (grade - 1 > 150)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrement(void)
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor was called." << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &src)
{
	stream << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return stream;
}