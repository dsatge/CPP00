# include "whatever.hpp"
# include <iostream>

int main(void)
{
    int a = 2;
    int b = 3;

    std::cout << "a = " << a << " b = " << b << std::endl;
    std::cout << "~~~ SWAP ~~~" << std::endl;
    swap(a, b);
    std::cout << "a = " << a << " b = " << b << std::endl;

    std::cout << "\na = " << a << " b = " << b << std::endl;
    std::cout << "~~~ min = " << min(a, b) << std::endl;
    

    std::cout << "\na = " << a << " b = " << b << std::endl;
    std::cout << "~~~ max = " << max(a, b) << std::endl;

    std::cout << "\n CHECK EQUALS SECOND ARGUMENT" << std::endl;
    a = 5;
    b = 5;
    std::cout << "a adress = " << &a << " | b adress = " << &b << std::endl;
    std::cout << "smallest adress = " << &min(a, b) << std::endl;
}