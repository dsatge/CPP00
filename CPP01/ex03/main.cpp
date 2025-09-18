#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main( void )
{
	{
	Weapon club = Weapon("shamefull laugh");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	{
	HumanB greg("Greg");
	greg.attack();
	Weapon club = Weapon("love");
	greg.setWeapon(club);
	greg.attack();
	club.setType("some other type of club");
	greg.attack();
	}
}