#include "Harl.hpp"

Harl::Harl( void )
{
	return ;
}

Harl::~Harl (void)
{
	return ;
}

void	Harl::debug( void )
{
	std::cerr << "DEBUG : this is a debug message" << std::endl;
}

void	Harl::info( void )
{
	std::cerr << "INFO : this is an info message" << std::endl;
}

void	Harl::warning( void )
{
	std::cerr << "WARNING : this is a warning message" << std::endl;
}

void	Harl::error( void )
{
	std::cerr << "ERROR : this is an error message" << std::endl;
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
			debug();
			break;
		case INFO:
			info();
			break;
		case WARNING:
			warning();
			break;
		case ERROR:
			error();
			break;
		case UNKNOWN:
			std::cerr << level 
			<< " : has no corresponding option. Please select debug, info, warning or error."
			<< std::endl;
			break;
	}
}
