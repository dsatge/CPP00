# include "ScalarConverter.hpp"
# include <cmath>
# include <iomanip>
# include <sstream>

ScalarConverter::ScalarConverter( void )
{
    return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
    return ;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this != &other)
    {
        *this = other;
    }
    return (*this);
}

ScalarConverter::~ScalarConverter( void )
{
    return ;
}

bool    is_char(const std::string& str)
{
    // Check if there is more than one char:
    int i = 0;
    while (str[i])
    i++;
    if (i > 1)
    return (false);

    // Check if str is ascii:
    if (str[0] < 0 && str[0] > 127)
        return (false);

    return (true);
}

bool    is_int(const std::string& str)
{
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (str[i] == '.' || !(str[i] >= '0' && str[i] <= '9'))
            return (false);
        i++;
    }
    return (true);
}

bool    is_float(const std::string& str)
{
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    // Check ending with f
    while (str[i])
        i++;
    if (str[i - 1] && str[i - 1] == 'f')
        return (true);
    return (false);
}

bool    is_double(const std::string& str)
{
    int i = 0;
    bool flagComa = false;
    
    // Check coma
    while (str[i])
    {
        if (str[i] == '.')
        flagComa = true;
        i++;
    }
    // Check NOT ending with f
    if (str[i - 1] && str[i - 1] == 'f')
        return (false);
    if (flagComa == false)
        return (false);
    return (true);
}

void    convert_from_char(const std::string c)
{
    std::cout << CYAN << "char: " << RESET;

    // Check for special cases as char:
    if (std::isnan(c[0]))
        std::cout << CYAN << "impossible" << RESET << std::endl;
    else if (c[0] < 0 && c[0] > 127)
        std::cout << CYAN << "Non displayable" << RESET << std::endl;
    else
        std::cout << CYAN << "'" << c << "'" << RESET << std::endl;
    // Convert to other scalar
    std::cout << "int: " << static_cast<int>(c[0]) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) 
            << static_cast<float>(c[0]) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c[0]) << std::endl;
}

void    convert_from_int(const std::string str)
{
    int nbr;
    std::stringstream ss(str);
    ss >> nbr;

    std::cout << "char: ";
    // Check for special cases as char:
    if (std::isnan(nbr))
        std::cout << "impossible" << std::endl;
    else if (nbr < 0 || nbr > 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(nbr) << "'" << std::endl;

    // convert int
    std::cout << CYAN << "int: " << nbr << RESET << std::endl;
        
    // Convert to other scalar
    std::cout << "float: " << std::fixed << std::setprecision(1) 
            << static_cast<float>(nbr) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
    try 
    {
        if (is_char(str) == true)
            convert_from_char(str);
        else if (is_int(str) == true)
            convert_from_int(str);
        else if (is_float(str) == true)
        {
            float nbr;
            std::stringstream ss(str);
            ss >> nbr;

            std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(nbr) << std::endl;
            std::cout << CYAN << "float: " << std::fixed << std::setprecision(1) 
                    << nbr << "f" << RESET << std::endl;
            std::cout << "double: " << static_cast<double>(nbr) << std::endl;

        }
        else if (is_double(str) == true)
        {
            double nbr;
            std::stringstream ss(str);
            ss >> nbr;

            std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(nbr) << std::endl;
            std::cout << "float: " << std::fixed << std::setprecision(1) 
                    << static_cast<float>(nbr) << "f" << std::endl;
            std::cout << CYAN << "double: " << nbr << RESET << std::endl;
        }
        else
            return ;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    // Char, int, float, double
}

//////// EXCEPTIONS

const char *ScalarConverter::IsWhiteSpace::what() const throw()
{
    return ("Non displayable");
}

const char* ScalarConverter::IsNotPossible::what() const throw()
{
    return ("impossible");
}