# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int main(void)
{
    // std::cout << CYAN << "Intern creates existing forms\n" << RESET << std::endl;
{
    std::cout << YELLOW << "////// Intern creates existing forms //////\n"
            << RESET << std::endl;
    try
    {
        Bureaucrat MacronDemission("Manu", 1);
        std::cout << MacronDemission << std::endl;
        // Create form
        Intern  SomeRandomIntern;
        AForm   *InternsForm;
        InternsForm = SomeRandomIntern.makeForm("presidential pardon request", "tom");
        MacronDemission.signForm(*InternsForm);
        InternsForm->execute(MacronDemission);
        std::cout << YELLOW << "////// Intern creates non existing form //////" << RESET << std::endl;
        delete (InternsForm);
        AForm   *weirdForm;
        weirdForm = SomeRandomIntern.makeForm("become emperor", "intern");
        MacronDemission.signForm(*weirdForm);
        weirdForm->execute(MacronDemission);
        delete (weirdForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
}
    return (0);
}