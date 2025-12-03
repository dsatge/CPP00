# include "BitcoinExchange.hpp"


//////////////////////////////////////////////////////////////////
////////////////////// CLASS  CONSTRUCTION  //////////////////////
//////////////////////////////////////////////////////////////////

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->_ExchangeRateData = other._ExchangeRateData;
    return ;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->_ExchangeRateData = other._ExchangeRateData;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    return ;
}

//////////////////////////////////////////////////////////////////
//////////////////////// UTILS FUNCTIONS  ////////////////////////
//////////////////////////////////////////////////////////////////

void    bissextileLen(std::string year, std::string day)
{
    int iyear;
    std::stringstream ss(year);
    ss >> iyear;
    if (iyear % 4 == 0)
    {
        if (day > "29")
            throw BitcoinExchange::BadInput();
    }
    else if (day > "28")
        throw BitcoinExchange::BadInput();
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
    while (std::getline(DataFile, line))
    {
        std::string date = getDate(line);
        float       rate = getRate(line);
        _ExchangeRateData[date] = rate;
    }
}

//////////////////////////////////////////////////////////////////
/////////////////////////// FUNCTIONS  ///////////////////////////
//////////////////////////////////////////////////////////////////

void    checkFormatDate(std::string date)
{
    std::string year;
    std::string month;
    std::string day;
    std::string separator;

    year = date.substr(0, 4);
    separator = date.substr(4, 1);
    if (separator != "-")
        throw BitcoinExchange::BadInput();
    month = date.substr(5, 2);
    separator = date.substr(7, 1);
    if (separator != "-")
        throw BitcoinExchange::BadInput();
    day = date.substr(8, 2);
    std::stringstream ss(month);
    validDate(year, month, day);
}

void    validDate(std::string year, std::string month, std::string day)
{
    int iday;
    std::stringstream ss(day);
    ss >> iday;
    std::string monthTab[12] = {
        "01",
        "02",
        "03",
        "04",
        "05",
        "06",
        "07",
        "08",
        "09",
        "10",
        "11",
        "12"};
    std::string dayTab[12] = {
        "31",
        "28",
        "31",
        "30",
        "31",
        "30",
        "31",
        "31",
        "30",
        "31",
        "30",
        "31"};
    for (int i = 0; i < 12; i++)
    {
        if (monthTab[i] == month)
        {
            if (month == "02")
                bissextileLen(year, day);
            else if (day > dayTab[i])
                throw BitcoinExchange::BadInput();
        }
    }
}

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
