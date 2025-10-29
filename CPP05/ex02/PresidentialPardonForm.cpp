# include "ShrubberyCreationForm.hpp"
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    return;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
    return ;
}

//// Methds ////

void    PresidentialPardonForm::execute(Bureaucrat const &executor)
{
    if (this->getSigned() == false)
        throw (AForm::FormNotSigned());
    if (executor.getGrade() > this->getRequiredExecuteGrade())
        throw (AForm::ExecutionAutorisationInvalid());
    std::cout << GREEN << executor.getName() 
            << " has been pardon by Zaphod Beeblebrox." << RESET
            << std::endl;
}

//// Exceptions ////
