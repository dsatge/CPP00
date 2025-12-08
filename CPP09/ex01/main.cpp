# include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);
    try
    {
        Rpn RevertedPolish(argv[1]);
        std::cout << RevertedPolish.calculate() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }
    
}