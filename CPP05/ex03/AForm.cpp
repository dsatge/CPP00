#include "AForm.hpp"
#include "Bureaucrat.hpp"
# include <iomanip>

////////////////////////////////////////////
///////////    Canonical AForm    ///////////

AForm::AForm(std::string name, int RequiredSigningGrade, int RequiredExecuteGrade) : _name(name),
_RequiredSigningGrade(RequiredSigningGrade), _RequiredExecuteGrade(RequiredExecuteGrade)
{
    if (this->_RequiredExecuteGrade < 1 || this->_RequiredSigningGrade < 1)
        throw GradeTooHigh();
    if (this->_RequiredExecuteGrade > 150 || this->_RequiredSigningGrade > 150)
        throw GradeTooLow();
    this->_signed = false;
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed),
_RequiredSigningGrade(other._RequiredSigningGrade), _RequiredExecuteGrade(other._RequiredExecuteGrade)
{
    return ;
}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

AForm::~AForm( void )
{
    return ;
}

////////////////////////////////////////////
///////////      Methodes        ///////////


void    AForm::beSigned(Bureaucrat &Bureaucrat)
{
    if (Bureaucrat.getGrade() >= this->getRequiredSigningGrade())
        throw (AForm::GradeTooLow());
    this->_signed = true;
}

std::string AForm::getName( void ) const
{
    return (this->_name);
}

bool AForm::getSigned( void ) const 
{
    return (this->_signed);
}

int AForm::getRequiredSigningGrade( void ) const
{
    return (this->_RequiredSigningGrade);
}

int AForm::getRequiredExecuteGrade( void ) const
{
    return (this->_RequiredExecuteGrade);
}

////////////////////////////////////////////
///////////      EXCEPTIONS      ///////////


const char* AForm::GradeTooHigh::what() const throw()
{
    return ("Grade is too high");
}

const char* AForm::GradeTooLow::what() const throw()
{
    return ("Grade is too low");
}

const char *AForm::ExecutionAutorisationInvalid::what() const throw()
{
    return ("Bureaucrat is not allowed to execute this Shrubbery form.");
}

const char*AForm::FormNotSigned::what() const throw()
{
    return ("The file hasn't been signed and cannot be executed if not.");
}
////////////////////////////////////////////
///////////       Overflow       ///////////

std::ostream& operator<<(std::ostream &out, const AForm &other)
{
    out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n|     AForm "
        << other.getName() << std::setw(11) << " |\n"
        << "| Signed : " << other.getSigned() << std::setw(24) << " |\n"
        << "| Required signing grade : " << other.getRequiredSigningGrade() << std::setw(6) << " |\n"
        << "| Required executing grade : " << other.getRequiredExecuteGrade() << std::setw(4) << " |\n"
        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    return (out);
}   
