# include "RobotomyRequestForm.hpp"
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    return;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
    return ;
}

//// Methods ////

void    RobotomyRequestForm::execute(Bureaucrat const &executor)
{
    if (this->getSigned() == false)
        throw (AForm::FormNotSigned());
    if (executor.getGrade() > this->getRequiredExecuteGrade())
        throw (AForm::ExecutionAutorisationInvalid());
    /////// get random odd or even number (50% chance)
    srand(time(0));
    int random = rand() %2;
    std::cout << "*Makes some drilling noise*\n" << std::endl;
    if (random == 0)
        throw (RobotomyRequestForm::FailedRobotomy());
    std::cout << GREEN << executor.getName()
            << " has been successfully robotomized" << RESET << std::endl;
}

//// Exceptions ////

const char* RobotomyRequestForm::FailedRobotomy::what() const throw()
{
    return ("Robotomy failed.");
}
