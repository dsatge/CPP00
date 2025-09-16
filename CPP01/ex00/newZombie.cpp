# include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie* new_zomb = new Zombie(name);
	new_zomb->announce();
	return (new_zomb);
};