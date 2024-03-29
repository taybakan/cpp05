#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}