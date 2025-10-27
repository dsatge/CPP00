# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(void)
{
{
    std::cout << YELLOW << "////// Create President signing signable form //////\n"
            << RESET << std::endl;
    try
    {
        Bureaucrat MacronDemission("Manu", 1);
        std::cout << "Bureaucrat " << MacronDemission.getName()
                << " is grade " << MacronDemission.getGrade() << std::endl;
        //// Create form
        Form LoiDuplomb("Loi Duplond", 5, 5);
        std::cout << LoiDuplomb << std::endl;
        MacronDemission.signForm(LoiDuplomb);
        }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
}
    std::cout << YELLOW << "\n////// Create intern signing form with no rights //////\n"
            << RESET << std::endl;
    try
    {
        Bureaucrat Intern("Intern Michel", 150);
        std::cout << Intern << std::endl;
        //// Create form
        Form LoiDuplomb("Loi Duplond", 5, 5);
        std::cout << LoiDuplomb << std::endl;
        Intern.signForm(LoiDuplomb);
        }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
{
    std::cout << YELLOW << "\n////// Signing form already signed //////\n"
            << RESET << std::endl;
    try
    {
        Bureaucrat MacronDemission("Manu", 1);
        std::cout << "Bureaucrat " << MacronDemission.getName()
                << " is grade " << MacronDemission.getGrade() << std::endl;
        //// Create form
        Form HumansRights("Human's rights", 100, 100);
        std::cout << HumansRights << std::endl;
        MacronDemission.signForm(HumansRights);
        std::cout << HumansRights << std::endl;
        Bureaucrat StupidIntern("Donald Trump", 89);
        std::cout << StupidIntern << std::endl;
        StupidIntern.signForm(HumansRights);
        }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
}
    return (0);
}