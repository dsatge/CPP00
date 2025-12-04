# include "BitcoinExchange.hpp"


//////////////////////////////////////////////////////////////////
////////////////////// CLASS  CONSTRUCTION  //////////////////////
//////////////////////////////////////////////////////////////////

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
////////////////////////  UTILS METHODS  /////////////////////////
//////////////////////////////////////////////////////////////////

std::string closestDate(std::string date, std::map<std::string, int> map)
{
    std::map<std::string, int>::iterator it = map.begin();
    if (date < it->first)
        throw BitcoinExchange::NoDateData();
    if (map.count(date) == 1)
        return date;
    else
    {
        
    }
        std::cout << "asked for diff dates" << std::endl;
    return (it->first);
}

//////////////////////////////////////////////////////////////////
///////////////////////////  METHODS  ////////////////////////////
//////////////////////////////////////////////////////////////////

void    BitcoinExchange::convert(std::string dataName)
{
    std::ifstream DataFile(dataName.c_str());
    if (csvFile(dataName) == false)
        throw FileNotReadable();
    if (!DataFile.good())
        throw FileNotReadable();
    if (!DataFile.is_open())
        throw FileNotReadable();
    std::string line;
    std::getline(DataFile, line);
    if (line != "date | value")
        throw WrongDataInfile();
    while (std::getline(DataFile, line))
    {
        std::string date;
        float       quantity;
        try
        {
            date = getDate(line);
            quantity = getQuantity(line);
            closestDate(date, _ExchangeRateData);
            std::cout << date << " => " << quantity << " = " << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        }
    }
}

//////////////////////////////////////////////////////////////////
//////////////////////// UTILS FUNCTIONS  ////////////////////////
//////////////////////////////////////////////////////////////////


bool    csvFile(std::string fileName)
{
    size_t  lenFileName = fileName.size();
    if (lenFileName < 4)
        return false;
    std::string fileType = fileName.substr((lenFileName - 4), 4);
    return (fileType == ".csv" ? true : false);
}

void    bissextileLen(std::string year, std::string day, std::string date)
{
    int iyear;
    std::stringstream ss(year);
    ss >> iyear;
    if (iyear % 4 == 0)
    {
        if (day > "29")
            throw BitcoinExchange::BadInput(date);
    }
    else if (day > "28")
        throw BitcoinExchange::BadInput(date);
}


std::string getDate(std::string line)
{
    std::string date;
    size_t      delimiterPos;
    delimiterPos = line.find(",", 0);
    if (delimiterPos > line.size())
        delimiterPos = line.find(" | ", 0);
    date = line.substr(0, (delimiterPos));
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
    return (fRate);
}

float getQuantity(std::string line)
{
    std::string quantity;
    size_t      startPos;
    size_t      endOfWord;
    float       fquantity;

    startPos = line.find("|", 0) + 1;
    endOfWord = line.size() - (startPos);
    quantity = line.substr(startPos, endOfWord);

    std::stringstream   ss(quantity);
    ss >> fquantity;
    if (fquantity < 0)
        throw BitcoinExchange::NegativeValue();
    if (fquantity > 10000)
        throw BitcoinExchange::TooHighValue();
    if (fquantity > 10000)
        throw BitcoinExchange::TooHighValue();
    return (fquantity);
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
        throw BitcoinExchange::BadInput(date);
    month = date.substr(5, 2);
    separator = date.substr(7, 1);
    if (separator != "-")
        throw BitcoinExchange::BadInput(date);
    day = date.substr(8, 2);
    std::stringstream ss(month);
    validDate(year, month, day, date);
}

void    validDate(std::string year, std::string month, std::string day, std::string date)
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
                bissextileLen(year, day, date);
            else if (day > dayTab[i])
                throw BitcoinExchange::BadInput(date);
            return ;
        }
    }
    throw BitcoinExchange::BadInput(date);
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

BitcoinExchange::BadInput::BadInput(const std::string &errorline) throw()
     : _errorfile("bad input => " + errorline)
{
    return ;
}
const char* BitcoinExchange::BadInput::what() const throw()
{
    return (_errorfile.c_str());
}

BitcoinExchange::BadInput::~BadInput() throw()
{
    return ;
}

const char* BitcoinExchange::NoDateData::what() const throw()
{
    return ("no data available at this date");
}
