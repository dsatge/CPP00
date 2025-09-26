# include <iostream>
# include <sstream>
# include <iomanip>
# include "contact.hpp"

# ifndef PHONEBOOK_HPP
    #define PHONEBOOK_HPP

class	PhoneBook
{
	private:
		Contact	_contactTable[8];
		int		_contactIndex;
		int		_contactMax;

	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact( void );
		void	search_contact( void );
		void	display_info(int i);
		void	index_info( void );
};
#endif