# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main(void)
{
    std::cout << CYAN << "SHRUBBERY TESTS FORMS\n" << RESET << std::endl;
{
    std::cout << YELLOW << "////// Create President signing and executing form //////\n"
            << RESET << std::endl;
    try
    {
        Bureaucrat MacronDemission("Manu", 1);
        std::cout << MacronDemission << std::endl;
        //// Create form
        Shrubbery treeplantationform("tree for my garden");
        // std::cout << treePlantationForm << std::endl;
        MacronDemission.signForm(treeplantationform);
        treeplantationform.execute(MacronDemission);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
}
{
    std::cout << YELLOW << "\n////// Executing unsigned form //////\n"
            << RESET << std::endl;
    try
    {
        Bureaucrat MacronDemission("Manu", 1);
        std::cout << MacronDemission << std::endl;
        //// Create form
        Shrubbery treeplantationform("tree for my garden");
        std::cout << treeplantationform << std::endl;
        treeplantationform.execute(MacronDemission);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
}
{
    std::cout << YELLOW << "\n////// Executing signed form from unautorized bureaucrat //////\n"
            << RESET << std::endl;
    try
    {
        Bureaucrat MacronDemission("Manu", 144);
        Bureaucrat NoobGardener("Bob", 138);
        std::cout << MacronDemission << std::endl;
        std::cout << NoobGardener << std::endl;
        //// Create form
        Shrubbery treeplantationform("tree for my garden");
        MacronDemission.signForm(treeplantationform);
        treeplantationform.execute(NoobGardener);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
}
std::cout << CYAN << "ROBOTOMY TESTS FORMS\n" << RESET << std::endl;
// {
//     std::cout << YELLOW << "////// Create President signing and executing form //////\n"
//             << RESET << std::endl;
//     try
//     {
//         Bureaucrat MacronDemission("Manu", 1);
//         std::cout << MacronDemission << std::endl;
//         //// Create form
//         RobotomyRequestForm myrobotform("IA form");
//         MacronDemission.signForm(myrobotform);
//         myrobotform.execute(MacronDemission);
//         std::cout << "Try again as it is random:" << std::endl;
//         myrobotform.execute(MacronDemission);
//         std::cout << "Try again as it is random:" << std::endl;
//         myrobotform.execute(MacronDemission);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
//     }
// }
// {
//     std::cout << YELLOW << "\n////// Executing unsigned form //////\n"
//             << RESET << std::endl;
//     try
//     {
//         Bureaucrat MacronDemission("Manu", 1);
//         std::cout << MacronDemission << std::endl;
//         //// Create form
//         RobotomyRequestForm myrobotform("IA form");
//         std::cout << myrobotform << std::endl;
//         myrobotform.execute(MacronDemission);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
//     }
// }
// {
//     std::cout << YELLOW << "\n////// Executing form from unautorized bureaucrat //////\n"
//             << RESET << std::endl;
//     try
//     {
//         Bureaucrat MacronDemission("Manu", 1);
//         Bureaucrat NoobGardener("Bob", 138);
//         std::cout << MacronDemission << std::endl;
//         std::cout << NoobGardener << std::endl;
//         //// Create form
//         RobotomyRequestForm myrobotform("IA form");
//         MacronDemission.signForm(myrobotform);
//         myrobotform.execute(NoobGardener);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
//     }
// }
std::cout << CYAN << "PRESIDENTIAL PARDON TEST FORM\n" << RESET << std::endl;
// {
//     std::cout << YELLOW << "////// Create President signing and executing form //////\n"
//             << RESET << std::endl;
//     try
//     {
//         Bureaucrat MacronDemission("Manu", 1);
//         std::cout << MacronDemission << std::endl;
//         //// Create form
//         PresidentialPardonForm Sorry("Oupsyy Im sorry");
//         MacronDemission.signForm(Sorry);
//         Sorry.execute(MacronDemission);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
//     }
// }
// {
//     std::cout << YELLOW << "\n////// Executing unsigned form //////\n"
//             << RESET << std::endl;
//     try
//     {
//         Bureaucrat MacronDemission("Manu", 1);
//         std::cout << MacronDemission << std::endl;
//         //// Create form
//         PresidentialPardonForm Sorry("Oupsyy Im sorry");
//         std::cout << Sorry << std::endl;
//         Sorry.execute(MacronDemission);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
//     }
// }
// {
//     std::cout << YELLOW << "\n////// Executing without permissions //////\n"
//             << RESET << std::endl;
//     try
//     {
//         Bureaucrat MacronDemission("Manu", 5);
//         std::cout << MacronDemission << std::endl;
//         //// Create form
//         PresidentialPardonForm Sorry("Oupsyy Im sorry");
//         MacronDemission.signForm(Sorry);
//         MacronDemission.decrementGrade();
//         std::cout << MacronDemission << std::endl;
//         Sorry.execute(MacronDemission);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
//     }
// }
    return (0);
}