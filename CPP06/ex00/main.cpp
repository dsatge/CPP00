#include "ScalarConverter.hpp"
# include <cmath>
# include <iomanip>
# include <sstream>

int main(int argc, char **argv)
{
    std::cout << "here is arg : " << argv[1] << std::endl;
    if (argc != 2)
        return (1);
    ScalarConverter scalar = ScalarConverter();
    scalar.convert(argv[1]);
    return (0);
}