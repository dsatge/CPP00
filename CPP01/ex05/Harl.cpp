#include "Harl.hpp"

Harl::Harl( void )
{
	return ;
}

Harl::~Harl (void)
{
	return ;
}

void	Harl::_debug( void )
{
	std::cout << "'DEBUG' level: I love having extra bacon "
		"for my 7XL-double-cheese-triple-pickle-special- "
		"ketchup burger. I really do!" << std::endl;
}

void	Harl::_info( void )
{
	std::cout << "'INFO' level: I cannot believe adding extra "
		"bacon costs more money. You didn’t put enough bacon "
		"in my burger! If you did, I wouldn’t be asking for "
		"more!" << std::endl;
}

void	Harl::_warning( void )
{
	std::cout << "'WARNING' level:  think I deserve to have "
		"some extra bacon for free. I’ve been coming for "
		"years, whereas you started working here just last "
		"month." << std::endl;
}

void	Harl::_error( void )
{
	std::cout << "'ERROR' level: This is unacceptable! I "
		"want to speak to the manager now." << std::endl;
}


void	level_convert(std::string levels[])
{
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	return ;
}

void	Harl::complain(std::string complain)
{
	void	(Harl::*ptr[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string levels[4];
	level_convert(levels);
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == complain)
		{
			(this->*ptr[i])();
			return ;
		}
	}
	std::cout << "'" << complain << "' level: complain level unknown"
	 		<< std::endl;
}
