#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm a("Soner");
	Bureaucrat b("Cemal", 150);
	a.beSigned(b);
	a.beSigned(b);
	a.beSigned(b);
	std::cout << a << std::endl;
	b.executeForm(a);

	return 0;
}