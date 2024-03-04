
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <fstream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	name;
		bool				is_signed;
		const int			to_sign;
		const int			to_exec;
	public:
		AForm();
		AForm(const std::string _name, const int _to_sign, const int _to_exec);
		AForm(const AForm &src);
		AForm &operator=(const AForm &rhs);
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getIsSigned(void) const;
		std::string getName(void) const;
		void beSigned(const Bureaucrat &signature);
		class GradeTooHighException : public std::exception{
			const char* what() const throw()
  			{
   				return "GradeTooHighException was thrown.";
  			}
		};
		class GradeTooLowException : public std::exception{
			const char* what() const throw()
  			{
				return "GradeTooLowException was thrown.";
  			}
		};
		class SignatureException : public std::exception
		{
            const char* what() const throw()
			{
				return "SignatureException was thrown.";
			};
        };
		virtual void execute(const Bureaucrat &signature) const = 0;
		virtual ~AForm();
};

std::ostream &operator<<(std::ostream &stream, const AForm &src);

#endif