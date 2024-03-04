#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const &src)
{
    *this = src;
}

Intern &Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return (*this);
}

Intern::~Intern(void)
{
}

static AForm *shrubberyCreation(std::string const target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *robotomyRequest(std::string const target)
{
    return new RobotomyRequestForm(target);   
}

static AForm *presidentialPardon(std::string const target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const formName, std::string const target) const
{
    AForm *r = NULL;
    std::string funcs[3] = {"shrubberyCreation", "robotomyRequest", "presidentialPardon"};
    funcArray formStringArray[3] = {&shrubberyCreation, &robotomyRequest, &presidentialPardon};
    int i = -1;
    while (i < 3)
    {
        i++;
        if (formName == funcs[i])
        {
            r = formStringArray[i](target);
            std::cout << "Intern creates " << r->getName() << std::endl;
            return r;
        }
    }
    throw UnknownFormException();
    return r;
}