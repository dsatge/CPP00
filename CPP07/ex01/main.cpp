# include "iter.hpp"
# include <iostream>

int main(void)
{
    int array[5] = {0, 1, 2, 3, 4};

    std::cout << YELLOW << "ARRAY TYPE INT : " << RESET << std::endl;
    std::cout << "test funtion print" << CYAN << " (const)" << RESET << std::endl;
    ::iter(array, 5, print_content);
    std::cout << "\ntest funtion + 10" << CYAN << " (const)" << RESET << std::endl;
    ::iter(array, 5, print_add_one);
    std::cout << "\ntest increase array" << CYAN << " (non const) " << RESET << "& print" << std::endl;
    ::iter(array, 5, increment);
    ::iter(array, 5, print_content);

    std::cout << YELLOW << "\n\nARRAY TYPE CHAR : " << RESET << std::endl;
    char arrayC[5] = {'H', 'E', 'L', 'L', 'O'};
    std::cout << "test funtion print" << CYAN << " (const)" << RESET << std::endl;
    ::iter(arrayC, 5, print_content);
    std::cout << "\ntest funtion + 10" << CYAN << " (const)" << RESET << std::endl;
    ::iter(arrayC, 5, print_add_one);
    std::cout << "\ntest increase array" << CYAN << " (non const) " << RESET << "& print" << std::endl;
    ::iter(arrayC, 5, increment);
    ::iter(arrayC, 5, print_content);

}