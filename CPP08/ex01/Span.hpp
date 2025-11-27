# ifndef SPAN_HPP
    # define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <list>
# include <vector>
# include <deque>
# include <limits.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class Span
{
    private:
        std::vector<int> _listContent;
        unsigned int _listSize;
        unsigned int _elementCount;
    public:
        Span(unsigned int listSize);
        Span(const Span &other);
        Span& operator=(const Span &other);
        ~Span();
    
        void addNumber(const int newVar);
        void addXNumbers(const int Elements);
        int shortestSpan(void);
        int longestSpan(void);
    
        class ContainerFull : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
        class ContainerEmpty : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
        class OneElement : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
        class OutOfRange : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
};

# endif