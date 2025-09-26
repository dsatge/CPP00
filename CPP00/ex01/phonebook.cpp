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

std::string	contact_sized(std::string info)
{
	int len_word = info.size();
	if (len_word <= 10)
		return (info);
	return (info.substr(0, 9) + ".");
}

void	PhoneBook::display_info(int i)
{
	std::cout << "Fist name: " << this->_contactTable[i].getFirstName() << std::endl
		<< "Last name: " << this->_contactTable[i].getLastName() << std::endl
		<< "Nickname: " << this->_contactTable[i].getNickName() << std::endl
		<< "Phone number: " << this->_contactTable[i].getPhoneNumber() << std::endl
		<< "Darkest secret: " << this->_contactTable[i].getDarkestSecret() << std::endl
		<< std::endl;
	return ;
}

void	PhoneBook::index_info( void )
{
	std::string line;
	getline(std::cin, line);
	std::stringstream index(line);
	long long i;
	if (!(index >> i))
		return ;
	index >> std::ws;
	if (!(index.eof()))
		return ;
	int	max = this->_contactMax;
		if (this->_contactMax == 0)
		max = this->_contactIndex;
	if (max == 0)
		return ;
	if (i > 8 || i < 0 || i >= max)
		return ;
	this->display_info(i);
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
			<< std::setw(10) << contact_sized(_contactTable[i].getFirstName()) << "|" 
			<< std::setw(10) << contact_sized(_contactTable[i].getLastName()) << "|"
			<< std::setw(10) << contact_sized(_contactTable[i].getNickName()) << "|"
			<< std::endl;
	}
	std::cout << "Press index number to see contact file" << std::endl;
	this->index_info();
	return ;
}
