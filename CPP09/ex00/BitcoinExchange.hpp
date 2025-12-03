# ifndef BITCOINEXCHANGE_HPP
    # define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <iomanip>
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

class BitcoinExchange
{
    private:
        std::map<std::string, int> _ExchangeRateData;   
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void convert(std::string dataFile);
        class FileNotReadable : public std::exception
        {
            virtual const char* what() const throw();
        };
        class WrongDataInfile : public std::exception
        {
            virtual const char* what() const throw();
        };
        class NegativeValue : public std::exception
        {
            virtual const char* what() const throw();
        };
        class BadInput : public std::exception
        {
            virtual const char* what() const throw();
        };
        class TooHighValue : public std::exception
        {
            virtual const char* what() const throw();
        };
        class NoDateData : public std::exception
        {
            virtual const char* what() const throw();
        };
        class OutOfRange : public std::exception
        {
            virtual const char* what() const throw();
        };
};

void    checkFormatDate(std::string date);
void    validDate(std::string year, std::string month, std::string day);
# endif
