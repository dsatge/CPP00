# ifndef PMERGEME_HPP
    # define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <deque>
# include <sstream>
# include <limits.h>
# include <algorithm>
# include <sys/time.h>
# include <iomanip>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class PmergeMe
{
    private:
        std::vector<int>   _Varray;
        std::deque<int>   _Darray;
    public:
        PmergeMe(std::string line);
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();
        void    sortFJohnosonAlgo(void);
        // class NegativeValues : public std::exception
        // {
        //     public:
        //         virtual const char* what() const throw();
        // };
        class ValueOutOfBound : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class UnautorizedCharacter : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

# endif