# ifndef RPN_HPP
    # define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class Rpn
{
    private:
        const std::string   _line;
    public:
        Rpn(std::string line);
        Rpn(const Rpn &other);
        // Rpn& operator=(const Rpn &other);
        ~Rpn();
        double calculate();
        class UnAuthorizedCharacter : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
        class MissingOperator : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
        class MissingNumber : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
        class DivZero : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
};

# endif