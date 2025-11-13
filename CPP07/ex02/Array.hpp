# ifndef ARRAY_HPP
    # define ARRAY_HPP

# include <iostream>
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
class Array
{
    private:
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array& operator=(const Array &other);
        ~Array();
};

# endif