# include "BitcoinExchange.hpp"
# include <fstream>

int main(int argc, char** argv)
{
    try
    {
        std::cout << YELLOW << "Exectue conversion with file given as parameters : " << RESET << std::endl;
        if (argc != 2)
            throw BitcoinExchange::FileNotReadable();
        BitcoinExchange mapList = BitcoinExchange();
        mapList.convert(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << '\n';
    }
    // try
    // {
    //     BitcoinExchange mapList = BitcoinExchange();
    //     std::cout << YELLOW << "Existing date x1 : " << RESET << std::endl;
    //     mapList.convert("ExistingDateQuantities.csv");
    //     std::cout << YELLOW << "\nNon existing date x1 : " << RESET << std::endl;
    //     mapList.convert("NewDateQuantities.csv");
    //     std::cout << YELLOW << "\nVariable quantites : " << RESET << std::endl;
    //     mapList.convert("VariableDateQuantities.csv");
    //     std::cout << YELLOW << "\nfiles full of exceptions : " << RESET << std::endl;
    //     mapList.convert("Exceptions.csv");
    //     std::cout << YELLOW << "\nWrong format file : " << RESET << std::endl;
    //     mapList.convert("Data.txt");
    //     std::cout << YELLOW << "\nWrong data Infile : " << RESET << std::endl;
    //     mapList.convert("WrongDataInfile.txt");
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << RED << "Error : " << e.what() << RESET << '\n';
    // }
    return (0);
}
