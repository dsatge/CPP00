# include "Span.hpp"

int main(void)
{
    std::cout << YELLOW << "Simple test and try adding extra Number in list" << RESET << std::endl;
    try
    {
        Span spanList(5);
        spanList.addNumber(6);
        spanList.addNumber(3);
        spanList.addNumber(-17);
        spanList.addNumber(9);
        spanList.addNumber(21);
        std::cout << GREEN << "Longest span : " << spanList.longestSpan() << RESET << std::endl;
        std::cout << GREEN << "shortest span : " << spanList.shortestSpan() << RESET << std::endl;
        // try to add a 7th element in list :
        std::cout << "Try to add 7th element to list" << std::endl;
        spanList.addNumber(78);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "\nEmpty list test" << RESET << std::endl;
    try
    {
        Span spanList(8);
        std::cout << GREEN << "Longest span : " << spanList.longestSpan() << RESET << std::endl;
        std::cout << GREEN << "shortest span : " << spanList.shortestSpan() << RESET << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "\nOnly one element to compare test" << RESET << std::endl;
    try
    {
        Span spanList(8);
        spanList.addNumber(372);
        std::cout << GREEN << "Longest span : " << spanList.longestSpan() << RESET << std::endl;
        std::cout << GREEN << "shortest span : " << spanList.shortestSpan() << RESET << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }    
    std::cout << YELLOW << "\nTest with a lot of data" << RESET << std::endl;
    try
    {
        Span spanList(10000);
        spanList.addXNumbers(10000);
        std::cout << GREEN << "Longest span : " << spanList.longestSpan() << RESET << std::endl;
        std::cout << GREEN << "shortest span : " << spanList.shortestSpan() << RESET << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "\nTest with limits" << RESET << std::endl;
    try
    {
        Span spanList(5);
        spanList.addNumber(2147483647);
        spanList.addNumber(-2147483648);
        std::cout << GREEN << "shortest span : " << spanList.shortestSpan() << RESET << std::endl;
        std::cout << GREEN << "Longest span : " << spanList.longestSpan() << RESET << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
    }
}