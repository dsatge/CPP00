#include <iostream>
# ifndef HARL_HPP
	# define HARL_HPP

enum level
{
	DEBUG = 1,
	INFO = 2,
	WARNING = 3,
	ERROR = 4,
	UNKNOWN = 0,
};

class	Harl
{
	private:
		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );

	public:
		Harl( void );
		void	complain(std::string level);
		~Harl( void );
};
#endif