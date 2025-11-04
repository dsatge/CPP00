# ifndef SCALARCONVERTER_HPP
    # define SCALARCONVERTER_HPP

#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class ScalarConverter
{
    private:
    public:
        //// CANONICAL
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        //// METHODS
        void convert(const std::string& str);
        //// EXCEPTIONS
        class IsWhiteSpace : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
        class IsNotPossible : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
};

# endif