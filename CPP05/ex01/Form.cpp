#include "Form.hpp"
#include "Bureaucrat.hpp"
# include <iomanip>

////////////////////////////////////////////
///////////    Canonical Form    ///////////

Form::Form(std::string name, int RequiredSigningGrade, int RequiredExecuteGrade) : _name(name),
_RequiredSigningGrade(RequiredSigningGrade), _RequiredExecuteGrade(RequiredExecuteGrade)
{
    if (this->_RequiredExecuteGrade < 1 || this->_RequiredSigningGrade < 1)
        throw GradeTooHigh();
    if (this->_RequiredExecuteGrade > 150 || this->_RequiredSigningGrade > 150)
        throw GradeTooLow();
    this->_signed = false;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed),
_RequiredSigningGrade(other._RequiredSigningGrade), _RequiredExecuteGrade(other._RequiredExecuteGrade)
{
    return ;
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

Form::~Form( void )
{
    return ;
}

////////////////////////////////////////////
///////////      Methodes        ///////////


void    Form::beSigned(Bureaucrat &Bureaucrat)
{
    if (Bureaucrat.getGrade() >= this->getRequiredSigningGrade())
        throw (Form::GradeTooLow());
    this->_signed = true;
}

std::string Form::getName( void ) const
{
    return (this->_name);
}

bool Form::getSigned( void ) const 
{
    return (this->_signed);
}

int Form::getRequiredSigningGrade( void ) const
{
    return (this->_RequiredSigningGrade);
}

int Form::getRequiredExecuteGrade( void ) const
{
    return (this->_RequiredExecuteGrade);
}

////////////////////////////////////////////
///////////      EXCEPTIONS      ///////////


const char* Form::GradeTooHigh::what() const throw()
{
    return ("Grade is too high");
}

const char* Form::GradeTooLow::what() const throw()
{
    return ("Grade is too low");
}

////////////////////////////////////////////
///////////       Overflow       ///////////

std::ostream& operator<<(std::ostream &out, const Form &other)
{
    out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n|     Form "
        << other.getName() << std::setw(11) << " |\n"
        << "| Signed : " << other.getSigned() << std::setw(24) << " |\n"
        << "| Required signing grade : " << other.getRequiredSigningGrade() << std::setw(6) << " |\n"
        << "| Required executing grade : " << other.getRequiredExecuteGrade() << std::setw(4) << " |\n"
        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    return (out);
}   
