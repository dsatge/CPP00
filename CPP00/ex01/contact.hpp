# include <iostream>
# ifndef CONTACT_HPP
    # define CONTACT_HPP

class Contact
{
private:
    std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string	_phoneNumber;
	std::string _darkestSecret;
public:
	Contact();
	~Contact();
	void	setFirstName(std::string &firstName);
	void	setLastName(std::string &lastName);
	void	setNickName(std::string &nickName);
	void	setPhoneNumber(std::string &phoneNumber);
	void	setDarkestSecret(std::string &darkestSecret);

	std::string	getFirstName( void );
	std::string	getLastName( void );
	std::string	getNickName( void );
	std::string	getPhoneNumber( void );
	std::string	getDarkestSecret( void );
};


#endif