# ifndef EASYFIND_HPP
    # define EASYFIND_HPP

# include <iostream>
# include <algorithm>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

template <typename T>
void easyfind(T& container, int valueToFind)
{
    if (std::find(container.begin(), container.end(), valueToFind) == container.end())
        throw std::runtime_error("Occurence not found.");
    std::cout << GREEN << valueToFind << " found in container" << RESET << std::endl;
}

# endif