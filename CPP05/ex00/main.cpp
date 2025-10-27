# include "Bureaucrat.hpp"

int main(void)
{
{
    std::cout << YELLOW << "////// Create President with max grade //////\n"
            << RESET << std::endl;
    try
    {
        Bureaucrat MacronDemission("Manu", 1);
        std::cout << "Bureaucrat " << MacronDemission.getName()
                << " is grade " << MacronDemission.getGrade() << std::endl;
        //// DOWN-GRADE
        std::cout << "Revolution, bureaucrat downgrade : " << std::endl;
        MacronDemission.decrementGrade();
        std::cout << GREEN << "Bureaucrat " << MacronDemission.getName()
            << " is grade " << MacronDemission.getGrade() << RESET << std::endl;
        //// UP-GRADE
        std::cout << "Attempt to come back president : " << std::endl;
        MacronDemission.incrementGrade();
        std::cout << GREEN << "Bureaucrat " << MacronDemission.getName()
            << " is grade " << MacronDemission.getGrade() << RESET << std::endl;
        //// UP-GRADE out of range
        std::cout << "Attempt to become Emperor : " << std::endl;
        MacronDemission.incrementGrade();
        std::cout << GREEN << "Bureaucrat " << MacronDemission.getName()
            << " is grade " << MacronDemission.getGrade() << RESET << std::endl;
        //// DOWN-GRADE after exception (should not appear)
        std::cout << "Revolution, bureaucrat downgrade : " << std::endl;
        MacronDemission.decrementGrade();
        std::cout << GREEN << "Bureaucrat " << MacronDemission.getName()
            << " is grade " << MacronDemission.getGrade() << RESET << std::endl;
        }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
}
{
    std::cout << YELLOW << "\n////// Create citizen not a bureaucrat //////\n"
            << RESET << std::endl;
    try 
    {
        Bureaucrat RegularCitizen("Bob", 163);
        std::cout << GREEN << "Bureaucrat " << RegularCitizen.getName()
            << " is grade " << RegularCitizen.getGrade() << RESET << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
}
{
    std::cout << YELLOW << "\n////// Create bureaucrat loosing power //////\n"
            << RESET << std::endl;
    try
    {
        Bureaucrat OverpaidBureaucrat("Anne", 150);
        std::cout << GREEN << "Bureaucrat " << OverpaidBureaucrat.getName()
            << " is grade " << OverpaidBureaucrat.getGrade() << RESET << std::endl;
        //// DOWN-GRADE
        std::cout << "Try : Revolution, bureaucrat downgrade : " << std::endl;
        OverpaidBureaucrat.decrementGrade();
        std::cout << GREEN << "Bureaucrat " << OverpaidBureaucrat.getName()
            << " is grade " << OverpaidBureaucrat.getGrade() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
}
    return (0);
}