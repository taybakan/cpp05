#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private :

	public :
		Intern(void);
		Intern(Intern const &src);
		Intern &operator=(Intern const &rhs);
		~Intern(void);
		AForm *makeForm(std::string form, std::string target) const;
		class UnknownFormException : public std::exception
		{
            const char* what() const throw()
			{
				return "UnknownFormException was thrown.";
			};
        };
};

typedef AForm*(*funcArray)(std::string);

#endif