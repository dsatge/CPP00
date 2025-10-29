# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "AForm.hpp"

////////////////////////////////////////////
///////        CANONICAL FORM        ///////

Intern::Intern(void)
{
    return ;
}

Intern::Intern(const Intern& other)
{
    *this = other;
    return ;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
    {
        *this = other;
    }
    return (*this);
}

Intern::~Intern( void )
{
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

AForm* Intern::createShrubbery(std::string target)
{
    AForm *form = new Shrubbery(target);
    return (form);
}

AForm* Intern::createRobotomy(std::string target)
{
    AForm *form = new RobotomyRequestForm(target);
    return (form);
}

AForm* Intern::createPresidential(std::string target)
{
    AForm *form = new PresidentialPardonForm(target);
    return (form);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string formsNames[3] = {
        "shrubbery request",
        "robotomy request",
        "presidential pardon request"};

    AForm*  (*creatFormPtr[3])(std::string) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential};
    for (int i = 0; i < 3; i++)
    {
        if (formName == formsNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return creatFormPtr[i](target);
        }
    }
    throw NoFormWithCorrespondingName();
}

////////////////////////////////////////////
///////////      EXCEPTIONS      ///////////

const char* Intern::NoFormWithCorrespondingName::what() const throw()
{
    return ("Intern tryed to create unexisting form");
}
