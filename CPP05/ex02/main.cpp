# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

int main(void)
{
//     std::cout << CYAN << "SHRUBBERY TESTS FORMS\n" << RESET << std::endl;
// {
//     std::cout << YELLOW << "////// Create President signing and executing form //////\n"
//             << RESET << std::endl;
//     try
//     {
//         Bureaucrat MacronDemission("Manu", 1);
//         std::cout << "Bureaucrat " << MacronDemission.getName()
//                 << " is grade " << MacronDemission.getGrade() << std::endl;
//         //// Create form
//         Shrubbery treeplantationform("tree in my personnel garden");
//         // std::cout << treePlantationForm << std::endl;
//         MacronDemission.signForm(treeplantationform);
//         treeplantationform.execute(MacronDemission);
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
//         std::cout << "Bureaucrat " << MacronDemission.getName()
//                 << " is grade " << MacronDemission.getGrade() << std::endl;
//         //// Create form
//         Shrubbery treeplantationform("tree in my personnel garden");
//         treeplantationform.execute(MacronDemission);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
//     }
// }
// {
//     std::cout << YELLOW << "\n////// Executing signed form from unautorized bureaucrat //////\n"
//             << RESET << std::endl;
//     try
//     {
//         Bureaucrat MacronDemission("Manu", 144);
//         Bureaucrat NoobGardener("Bob", 138);
//         std::cout << "Bureaucrat " << MacronDemission.getName()
//                 << " is grade " << MacronDemission.getGrade() << std::endl;
//         std::cout << "Bureaucrat " << NoobGardener.getName()
//                 << " is grade " << NoobGardener.getGrade() << std::endl;
//         //// Create form
//         Shrubbery treeplantationform("tree in my personnel garden");
//         MacronDemission.signForm(treeplantationform);
//         treeplantationform.execute(NoobGardener);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
//     }
// }
std::cout << CYAN << "ROBOTOMY TESTS FORMS\n" << RESET << std::endl;
{
    std::cout << YELLOW << "////// Create President signing and executing form //////\n"
            << RESET << std::endl;
    try
    {
        Bureaucrat MacronDemission("Manu", 1);
        std::cout << "Bureaucrat " << MacronDemission.getName()
                << " is grade " << MacronDemission.getGrade() << std::endl;
        //// Create form
        RobotomyRequestForm myrobotform("IA form");
        MacronDemission.signForm(myrobotform);
        myrobotform.execute(MacronDemission);
        std::cout << "Try again as it is random:" << std::endl;
        myrobotform.execute(MacronDemission);
        std::cout << "Try again as it is random:" << std::endl;
        myrobotform.execute(MacronDemission);
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
        std::cout << "Bureaucrat " << MacronDemission.getName()
                << " is grade " << MacronDemission.getGrade() << std::endl;
        //// Create form
        RobotomyRequestForm myrobotform("IA form");
        myrobotform.execute(MacronDemission);
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
        std::cout << "Bureaucrat " << MacronDemission.getName()
                << " is grade " << MacronDemission.getGrade() << std::endl;
        std::cout << "Bureaucrat " << NoobGardener.getName()
                << " is grade " << NoobGardener.getGrade() << std::endl;
        //// Create form
        RobotomyRequestForm myrobotform("IA form");
        MacronDemission.signForm(myrobotform);
        myrobotform.execute(NoobGardener);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
}
std::cout << CYAN << "ROBOTOMY TESTS FORMS\n" << RESET << std::endl;

    return (0);
}