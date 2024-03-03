#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		std::string const	name;
		int					grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const _name, int _grade);
		Bureaucrat(const Bureaucrat &src);
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
		void increment(void);
		void decrement(void);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		std::string getName(void) const;
		int getGrade(void) const;
		~Bureaucrat(void);
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &src);

#endif