# include "Array.hpp"
# include <iostream>

int main(void)
{
    Array<int> list(5);

    std::cout << YELLOW << "~~~ TEST WITH INT ~~~" << RESET << std::endl;
    try
    {
        list[0] = 1;
        list[1] = 2;
        list[2] = 3;
        list[3] = 4;
        list[4] = 5;

        std::cout << "VALID INT LIST RETURNS :" << std::endl;
        std::cout << "List size is: " << list.size() << std::endl;
        std::cout << list[0] << ", " << list[1] << ", " << list[2]
                << ", " << list[3] << ", " << list[4] << std::endl;
        std::cout << "OUT OF BOUND LIST RETURNS :" << std::endl;
        std::cout << "List size is: " << list.size() << std::endl;
        std::cout << list[5] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }
    Array<int> test_list(3);
    test_list[0] = 41;
    test_list[1] = 42;
    test_list[2] = 43;

    const Array<int> const_list = test_list;

    std::cout << YELLOW << "~~~ TEST WITH CONST INT ~~~" << RESET << std::endl;
    try
    {
        std::cout << "VALID INT cLIST RETURNS :" << std::endl;
        std::cout << "cList size is: " << const_list.size() << std::endl;
        std::cout << const_list[0] << ", " << const_list[1] << ", " << const_list[2]
                << ", " << const_list[3] << ", " << const_list[4] << std::endl;
        std::cout << "OUT OF BOUND cLIST RETURNS :" << std::endl;
        std::cout << "cList size is: " << const_list.size() << std::endl;
        std::cout << const_list[5] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "~~~ TEST WITH CHAR ~~~" << RESET << std::endl;
    Array<std::string> tab(3);
    try
    {
        tab[0] = "hello ";
        tab[1] = "greatest ";
        tab[2] = "team";
                std::cout << "VALID CHAR LIST RETURNS :" << std::endl;
        std::cout << "List size is: " << tab.size() << std::endl;
        std::cout << tab[0] << ", " << tab[1] << ", " << tab[2]
                << std::endl;
        std::cout << "OUT OF BOUND LIST RETURNS :" << std::endl;
        std::cout << tab[3] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }    
}