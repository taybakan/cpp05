#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			to_sign;
		const int			to_exec;
	public:
		Form();
		Form(const std::string _name, const int _to_sign, const int _to_exec);
		Form(const Form &src);
		Form &operator=(const Form &rhs);
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getIsSigned(void) const;
		std::string getName(void) const;
		void beSigned(const Bureaucrat &signature);
		class GradeTooHighException : public std::exception{
			const char* what() const throw()
  			{
   				return " GradeTooHighException was thrown.";
  			}
		};
		class GradeTooLowException : public std::exception{
			const char* what() const throw()
  			{
				return " GradeTooLowException was thrown.";
  			}
		};
};

std::ostream &operator<<(std::ostream &stream, const Form &src);

#endif