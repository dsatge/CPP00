#include "Bureaucrat.hpp"
#include "Form.hpp"

////////////////////////////////////////////
///////        CANONICAL FORM        ///////

Bureaucrat::Bureaucrat(void) : _name("A random bureaucrat") , _grade(150)
{
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
    return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

Bureaucrat::Bureaucrat (std::string name, int grade) : _name(name)
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
    this->_grade = grade;
    return ;
}

const std::string Bureaucrat::getName( void ) const
{
    return (this->_name);
}

int Bureaucrat::getGrade( void ) const
{
    return (this->_grade);
}

void    Bureaucrat::incrementGrade( void )
{
    this->_grade -= 1;
    if (this->_grade < 1)
        throw GradeTooHighException();
    return ;
}

void    Bureaucrat::decrementGrade( void )
{
    this->_grade += 1;
    if (this->_grade > 150)
        throw GradeTooLowException();
    return ;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
    out << other.getName() << ", bureaucrat grade " << other.getGrade()
            << "." << std::endl;
    return (out);
}

void    Bureaucrat::signForm(Form &Form)
{
    if (Form.getSigned() == true)
    {
        std::cerr << RED << this->getName() << " couldn't sign " << Form.getName()
                << " because "
                << "the form is already signed." << RESET 
                << std::endl;
        // throw FormAlreadySigned();
    }
    else
    {
        Form.beSigned(*this);
        std::cout << GREEN << this->getName() << " signed " << Form.getName()
                << RESET << std::endl;
    }
}

////////////////////////////////////////////
///////////      EXCEPTIONS      ///////////

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char* Bureaucrat::FormAlreadySigned::what() const throw()
{
    return ("form already signed");
}
