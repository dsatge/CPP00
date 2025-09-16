# include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie* randoZomb = new Zombie(name);
    randoZomb->announce();
    delete(randoZomb);
    return ;
}