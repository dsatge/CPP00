# include "Bureaucrat.hpp"

int main(void)
{
    {
    std::cout << YELLOW << "////// Create President with max grade //////\n"
            << RESET << std::endl;
    Bureaucrat* MacronDemission = new Bureaucrat("Manu", 1);
    std::cout << "Bureaucrat " << MacronDemission->getName()
            << " is grade " << MacronDemission->getGrade() << std::endl;
    try
    {
        //// DOWN-GRADE
        std::cout << "Revolution, bureaucrat downgrade : " << std::endl;
        MacronDemission->decrementGrade();
        std::cout << GREEN << "Bureaucrat " << MacronDemission->getName()
            << " is grade " << MacronDemission->getGrade() << RESET << std::endl;
        //// UP-GRADE
        std::cout << "Attempt back to president : " << std::endl;
        MacronDemission->incrementGrade();
        std::cout << GREEN << "Bureaucrat " << MacronDemission->getName()
            << " is grade " << MacronDemission->getGrade() << RESET << std::endl;
        //// UP-GRADE out of range
        std::cout << "Attempt to become Emperor : " << std::endl;
        MacronDemission->incrementGrade();
        std::cout << GREEN << "Bureaucrat " << MacronDemission->getName()
            << " is grade " << MacronDemission->getGrade() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
    delete (MacronDemission);
    }
    {
    std::cout << YELLOW << "////// Create citizen not a bureaucrat //////\n"
            << RESET << std::endl;
    Bureaucrat *RegularCitizen = new Bureaucrat("Bob", 163);
    std::cout << GREEN << "Bureaucrat " << RegularCitizen->getName()
        << " is grade " << RegularCitizen->getGrade() << RESET << std::endl;
    delete (RegularCitizen);
    }
    {
    std::cout << YELLOW << "////// Create bureaucrat loosing power //////\n"
            << RESET << std::endl;
    Bureaucrat *OverpaidBureaucrat = new Bureaucrat("Anne", 150);
    std::cout << GREEN << "Bureaucrat " << OverpaidBureaucrat->getName()
        << " is grade " << OverpaidBureaucrat->getGrade() << RESET << std::endl;
    try
    {
        //// DOWN-GRADE
        std::cout << "Revolution, bureaucrat downgrade : " << std::endl;
        OverpaidBureaucrat->decrementGrade();
        std::cout << GREEN << "Bureaucrat " << OverpaidBureaucrat->getName()
            << " is grade " << OverpaidBureaucrat->getGrade() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
    }
    return (0);
}