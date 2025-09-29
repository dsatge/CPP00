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
	std::cout << "[ DEBUG]\nI love having extra bacon "
		"for my 7XL-double-cheese-triple-pickle-special- "
		"ketchup burger. I really do!\n" << std::endl;
}

void	Harl::_info( void )
{
	std::cout << "[ INFO ]\nI cannot believe adding extra "
		"bacon costs more money. You didn’t put enough bacon "
		"in my burger! If you did, I wouldn’t be asking for "
		"more!\n" << std::endl;
}

void	Harl::_warning( void )
{
	std::cout << "[ WARNING ]\nthink I deserve to have "
		"some extra bacon for free. I’ve been coming for "
		"years, whereas you started working here just last "
		"month.\n" << std::endl;
}

void	Harl::_error( void )
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I "
		"want to speak to the manager now.\n" << std::endl;
}

int	level_convert(std::string &level)
{
	if (level == "debug" || level == "DEBUG")
		return (1);
	if (level == "info" || level == "INFO")
		return (2);
	if (level == "warning" || level == "WARNING")
		return (3);
	if (level == "error" || level == "ERROR")
		return (4);
	return (0);
}

void	Harl::complain(std::string level)
{
	int	level_value = level_convert(level);
	switch (level_value)
	{
		case DEBUG:
			_debug();
		case INFO:
			_info();
		case WARNING:
			_warning();
		case ERROR:
			_error();
			break;
		case UNKNOWN:
			std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
			break;
	}
}
