#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main( void )
{
	Weapon club = Weapon("shamefull laugh");

	HumanA bob("Bob", club);
	bob.attack();
	club.setType("wood stick");
	bob.attack();

	HumanB Greg("Greg");
	Greg.attack();
	club.setType("love");
	Greg.attack();
	bob.attack();

}