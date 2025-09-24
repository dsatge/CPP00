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
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:
		Harl( void );
		void	complain(std::string level);
		~Harl( void );
};
#endif