# include "phonebook.hpp"
# include "contact.hpp"

PhoneBook::PhoneBook ( void )
{
    this->_contactIndex = 0;
	this->_contactMax = 0;
	return ;
}

PhoneBook::~PhoneBook( void )
{
    return ;
}

void	PhoneBook::add_contact( void )
{
	Contact newContact = Contact();
	std::string line;

	std::cout << "First name : ";
	getline(std::cin, line);
	newContact.setFirstName(line);

	std::cout << "Last name : ";
	getline(std::cin, line);
	newContact.setLastName(line);

	std::cout << "Nickname : ";
	getline(std::cin, line);
	newContact.setNickName(line);

	std::cout << "Phone number : ";
	getline(std::cin, line);
	newContact.setPhoneNumber(line);

	std::cout << "Darkest secret : ";
	getline(std::cin, line);
	newContact.setDarkestSecret(line);

	_contactTable[_contactIndex] = newContact;
	_contactIndex++;
	if (_contactIndex >= 8)
	{
		_contactIndex = 0;
		_contactMax = 8;
	}
	std::cout << "Contact successfully added !" << std::endl;
}

void	PhoneBook::search_contact( void )
{
	std::cout << std::setw(10) << "Index"
			<< "|" << std::setw(10) << "firstname"
			<< "|" << std::setw(10) << "lastname"
			<< "|" << std::setw(10) << "nickname"
			<< "|" << std::endl;
	int	indexMax;
	if (_contactMax == 0)
		indexMax = _contactIndex;
	else
		indexMax = _contactMax;
	for (int i = 0; i < indexMax; i++)
	{
		std::cout << std::setw(10) << i << "|" 
			<< std::setw(10) << _contactTable[i].getFirstName() << "|" 
			<< std::setw(10) << _contactTable[i].getLastName() << "|"
			<< std::setw(10) << _contactTable[i].getNickName() << "|"
			<< std::endl;
	}
	return ;
}
