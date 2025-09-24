# include "phonebook.hpp"

int	main( void )
{
	std::cout << "PhoneBook 2.0\nchoose: ADD, SEARCH, EXIT" << std::endl;
	PhoneBook PhoneBook;
	while (1)
	{
		std::string line;
		getline(std::cin, line);
		if (line == "ADD")
			PhoneBook.add_contact();
		if (line == "SEARCH")
			PhoneBook.search_contact();
		if (line == "EXIT")
			return (0);
		if (std::cin.eof())
			return (0);
	}
	
}