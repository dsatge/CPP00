#include "Weapon.hpp"
#include "HumanA.hpp"

int	main( void )
{
	Weapon club = Weapon("ice stick");

	HumanA bob("bob", club);
}