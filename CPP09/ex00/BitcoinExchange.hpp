# ifndef BITCOINEXCHANGE_HPP
    # define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class BitcoinExchange
{
    private:
    public:
        BitcoinExchange(std::istream file);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        class WrongArgumentCount : public std::exception
        {
            virtual const char* what() const throw();
        };
        class WrongFileFormat : public std::exception
        {
            virtual const char* what() const throw();
        };
        class FileNotReadable : public std::exception
        {
            virtual const char* what() const throw();
        };
        class WrongValueFormat : public std::exception
        {
            virtual const char* what() const throw();
        };
        class BadInput : public std::exception
        {
            virtual const char* what() const throw();
        };
        class NegativNumber : public std::exception
        {
            virtual const char* what() const throw();
        };
};

# endif