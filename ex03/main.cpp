#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try {
		PresidentialPardonForm a("Soner");
		Bureaucrat b("Cemal", 1);
		a.beSigned(b);
		a.beSigned(b);
		a.beSigned(b);
		std::cout << a << std::endl;
		b.executeForm(a);
		b.executeForm(a);
		b.executeForm(a);
		b.executeForm(a);

		Intern c;
		AForm *f;
		f = c.makeForm("robotomyRequest", "target");
		f->execute(b);
		f = c.makeForm("shrubberyCreation", "target");
		b.signForm(*f);
		f->execute(b);
		delete f;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}