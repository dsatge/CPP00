# include "Zombie.hpp"

int	main(void)
{
	Zombie foo = Zombie("Bobby");
	Zombie* newZomb;

	foo.announce();
	newZomb = newZombie("Robb");
	newZomb->announce();
	randomChump("Brandon");
	delete(newZomb);
	return (0);
}