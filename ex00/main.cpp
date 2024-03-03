#include "Bureaucrat.hpp"

int main()
{
	try{
	Bureaucrat bureaucrat1("nam", -1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}