# ifndef BITCOINEXCHANGE_HPP
    # define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <iomanip>
# include <limits.h>
# include <exception>

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

        void convert(std::string dataName);
        class FileNotReadable : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class WrongDataInfile : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NegativeValue : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class BadInput : public std::exception
        {
            private:
                std::string _errorfile;
            public:
                BadInput(const std::string &errorLine) throw();
                virtual const char* what() const throw();
                virtual ~BadInput() throw();
        };
        class TooHighValue : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NoDateData : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NoQuantityData : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class OutOfRange : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

void        checkFormatDate(std::string date);
bool        csvFile(std::string fileName);
std::string getDate(std::string line);
float       getRate(std::string line);
float       getQuantity(std::string line);
void        validDate(std::string year, std::string month, std::string day, std::string date);

# endif
