# include "BitcoinExchange.hpp"

void    checkFormatDate(std::string date)
{
    std::string year;
    std::string month;
    std::string day;

    year = date.substr(0, 4);
    month = date.substr(5, 2);
    day = date.substr(8, 2);
    // std::cout << "year: " << year
    //         << " / month: " << month
    //         << " / day: " << day << std::endl;
}

std::string getDate(std::string line)
{
    std::string date;
    size_t      delimiterPos;
    delimiterPos = line.find(",", 0);
    date = line.substr(0, delimiterPos);
    checkFormatDate(date);
    return (date);
}

float getRate(std::string line)
{
    std::string rate;
    size_t      startPos;
    size_t      endOfWord;
    float       fRate;

    startPos = line.find(",", 0) + 1;
    endOfWord = line.size() - (startPos);
    rate = line.substr(startPos, endOfWord);

    std::stringstream   ss(rate);
    ss >> fRate;
    if (fRate > static_cast<float>(INT_MAX))
        throw BitcoinExchange::OutOfRange();
    if (fRate < 0)
        throw BitcoinExchange::NegativeValue();
    // if (fRate > 10000)
    //     throw BitcoinExchange::TooHighValue();
    return (fRate);
}

BitcoinExchange::BitcoinExchange()
{
    std::ifstream DataFile("data.csv");
    if (!DataFile.good())
        throw FileNotReadable();
    if (!DataFile.is_open())
        throw FileNotReadable();
    std::string line;
    std::getline(DataFile, line);
    if (line != "date,exchange_rate")
        throw WrongDataInfile();
    std::cout << "first line recognise as: date,exchange_rate" << std::endl;
    while (std::getline(DataFile, line))
    {
        std::string date = getDate(line);
        // std::cout << "test date : " << date << std::endl;
        float       rate = getRate(line);
        std::cout << "test rate : " << rate << std::endl;
        _ExchangeRateData[date] = rate;
    }
}

BitcoinExchange::~BitcoinExchange()
{
    return ;
}

        // BitcoinExchange(const BitcoinExchange &other);
        // BitcoinExchange& operator=(const BitcoinExchange &other);


//////////////////////////////////////////////////////////////////
/////////////////////////// EXCEPTIONS ///////////////////////////
//////////////////////////////////////////////////////////////////

const char* BitcoinExchange::FileNotReadable::what() const throw()
{
    return ("could not open file");
}

const char* BitcoinExchange::WrongDataInfile::what() const throw()
{
    return ("wrong data stored in file");
}

const char* BitcoinExchange::NegativeValue::what() const throw()
{
    return ("not a positive number");
}

const char* BitcoinExchange::TooHighValue::what() const throw()
{
    return ("value number too high");
}

const char* BitcoinExchange::OutOfRange::what() const throw()
{
    return ("too large number");
}

const char* BitcoinExchange::BadInput::what() const throw()
{
    return ("bad input");
}

const char* BitcoinExchange::NoDateData::what() const throw()
{
    return ("wrong format date");
}
