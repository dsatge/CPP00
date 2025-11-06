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
    // Check special math form
    if (str == "inff" || str == "-inff" || str == "inf" | str == "-inf"
            || str == "nan" || str == "nanf")
        return (false);

    // Check if there is more than one char:
    int i = 0;
    while (str[i])
    i++;
    if (i > 1)
    return (false);

    // Check if str is ascii:
    if (str[0] <= 0 && str[0] >= 127)
        return (false);
    // Check if str is num:
    if (str[0] >= '0' && str[0] <= '9')
        return (false);
    return (true);
}

bool    is_int(const std::string& str)
{
    // Check special math form
    if (str == "inff" || str == "-inff" || str == "inf" | str == "-inf"
            || str == "nan" || str == "nanf")
        return (false);

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
    // check for math form
    if (str == "inff" || str == "-inff" || str == "nanf")
        return (true);
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;

    // Check ending with f
    while (str[i])
        i++;
    if (str[i - 1] && str[i - 1] == 'f'
            && !(str == "inf" || str == "-inf" || str == "nan"))
        return (true);
    return (false);
}

bool    is_double(const std::string& str)
{
    // check for math form
    if (str == "inf" || str == "-inf" || str == "nan")
        return (true);
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
    if (c == "inff" || c == "-inff" || c == "inf" | c == "-inf"
            || c == "nan" || c == "nanf" || c[0] > 127 || c[0] < 0)
        std::cout << CYAN << "impossible" << RESET << std::endl;
    else if (c[0] < 32 || c[0] > 126)
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
    long    nbr_overflow;
    int nbr;
    std::stringstream ss(str);
    ss >> nbr_overflow;
    nbr = static_cast<int>(nbr_overflow);

    std::cout << "char: ";
    // Check for special cases as char:
    if (std::isnan(nbr) || nbr > 127 || nbr < 0)
        std::cout << "impossible" << std::endl;
    else if (nbr < 32 || nbr > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(nbr) << "'" << std::endl;

    // int max check
    if (nbr_overflow > INT_MAX || nbr_overflow < INT_MIN)
        std::cout << CYAN << "int: impossible" << RESET << std::endl;
    else
        std::cout << CYAN << "int: " << nbr << RESET << std::endl;
        
    // Convert to other scalar
    std::cout << "float: " << std::fixed << std::setprecision(1) 
            << static_cast<float>(nbr) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

void    convert_from_float(const std::string str)
{
    float nbr;
    std::stringstream ss(str);
    ss >> nbr;

    // Check for special cases as char:
    if (nbr > 127 || nbr < 0 || str == "inff"
            || str == "-inff" || str == "nanf")
        std::cout << "char: impossible" << std::endl;
    else if (nbr < 32 || nbr > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;

    // Check math forms
    if (str == "inff" || str == "-inff" || str == "nanf")
    {
        std::cout << "int: impossible" << std::endl;
        std::cout << CYAN << "float: " << str << RESET << std::endl;
        std::cout << "double: " << str << std::endl;
        return ;
    }

    // convert to other scalar
    // int max check
    long nbr_overflow = static_cast<long>(nbr);
    if (nbr_overflow > INT_MAX || nbr_overflow < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << nbr << std::endl;
    
    // Convert float
    std::cout << CYAN << "float: " << std::fixed << std::setprecision(1) 
        << nbr << "f" << RESET << std::endl;

    //convert other scalar
    std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

void    convert_from_double(const std::string str)
{
    double nbr;
    std::stringstream ss(str);
    ss >> nbr;

    std::cout << "char: ";
    // Check for special cases as char:
    if (nbr > 127 || nbr < 0 || str == "inf" || str == "-inf" || str == "nan")
        std::cout << "impossible" << std::endl;
    else if (nbr < 32 || nbr > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(nbr) << "'" << std::endl;

    // Check math forms
    if (str == "inf" || str == "-inf" || str == "nan")
    {
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        std::cout << CYAN << "double: " << str << RESET << std::endl;
        return ;
    }
    
    // convert to other scalar        
    // int max check
    long nbr_overflow = static_cast<long>(nbr);
    if (nbr_overflow > INT_MAX || nbr_overflow < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << nbr << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) 
            << nbr << "f" << std::endl;

    // Convert double
    std::cout << CYAN << "double: " << nbr << RESET << std::endl;
}


void ScalarConverter::convert(const std::string& str)
{
    if (is_char(str) == true)
        convert_from_char(str);
    else if (is_int(str) == true)
        convert_from_int(str);
    else if (is_float(str) == true)
        convert_from_float(str);
    else if (is_double(str) == true)
        convert_from_double(str);
    else
        return ;
}
