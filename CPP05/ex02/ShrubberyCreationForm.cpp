# include "ShrubberyCreationForm.hpp"
# include "AForm.hpp"
# include "Bureaucrat.hpp"

Shrubbery::Shrubbery(std::string name) : AForm(name, 145, 137)
{
    return ;
}

Shrubbery::Shrubbery(const Shrubbery &other) : AForm(other)
{
    return;
}

Shrubbery& Shrubbery::operator=(const Shrubbery &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

Shrubbery::~Shrubbery( void )
{
    return ;
}

//// Methds ////

void    Shrubbery::execute(Bureaucrat const &executor)
{
    if (this->getSigned() == false)
        throw (AForm::FormNotSigned());
    if (executor.getGrade() > this->getRequiredExecuteGrade())
        throw (AForm::ExecutionAutorisationInvalid());
    std::string replaceFile = executor.getName() + "_shrubbery";
	std::ofstream outfile(replaceFile.c_str());
	if (!outfile)
        throw (Shrubbery::FailCreateOutfile());
    if (!outfile.good())
        throw (Shrubbery::FailOpenWriteOutfile());
    outfile << "     ccee88oo                  ccee88oo\n"
            << "  C8O8O8Q8PoOb o8oo           C8O8O8Q8PoOb o8oo\n"
            << " dOB69QO8PdUOpugoO9bD    dOB69QO8PdUOpugoO9bD\n"
            << "CgggbU8OU qOp qOdoUOdcb   CgggbU8OU qOp qOdoUOdcb\n"
            << "    6OuU  /p u gcoUodpP     6OuU  /p u gcoUodpP\n"
            << "      \'\'\'//  /douUP       \'\'\'//  /douUP\n"
            << "        \'\'\'////             \'\'\'////\n"
            << "         |||/\'                  |||/\'\n"
            << "         |||\'/                  |||\'/\n"
            << "         |||||               ,   |||||\n"
            << "   .....//||||\'....       ..( )..//||||\'....";
    outfile.close();
}

//// Exceptions ////

const char* Shrubbery::FailCreateOutfile::what() const throw()
{
    return ("Fail creating outfile");
}

const char* Shrubbery::FailOpenWriteOutfile::what() const throw()
{
    return ("No access permission");
}
