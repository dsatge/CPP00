# include <iostream>
# include "easyfind.hpp"
# include <list>
# include <deque>
# include <vector>

int main(void)
{
    std::cout << YELLOW << "~~~ TEST CONTAINER LIST" << RESET << std::endl;
    try
    {
        std::list<int> iList;
        iList.push_back(1);
        iList.push_back(10);
        iList.push_back(20);
        iList.push_back(30);
        easyfind(iList, 20);
        std::cout << "test easyfind with int 4 not in list :" << std::endl;
        easyfind(iList, 4);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET << '\n';
    }
    std::cout << YELLOW << "\n~~~ TEST CONTAINER DEQUE" << RESET << std::endl;
    try
    {
        std::deque<int> iList;
        iList.push_back(2);
        iList.push_back(12);
        iList.push_back(22);
        iList.push_back(32);
        easyfind(iList, 22);
        std::cout << "test easyfind with int 4 not in deque :" << std::endl;
        easyfind(iList, 4);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET << '\n';
    }
    std::cout << YELLOW << "\n~~~ TEST CONTAINER VECTOR" << RESET << std::endl;
    try
    {
        std::vector<int> iList;
        iList.push_back(2);
        iList.push_back(12);
        iList.push_back(22);
        iList.push_back(32);
        easyfind(iList, 22);
        std::cout << "test easyfind with int 4 not in vector :" << std::endl;
        easyfind(iList, 4);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET << '\n';
    }
}