# include "Zombie.hpp"

//////// Constructor ////////
Zombie::Zombie()
{
}

//////// Destructor ////////
Zombie::~Zombie( void )
{
	std::cout << this->_name << " has been destroyed" << std::endl;
	return ;
}
void Zombie::SetName(std::string name)
{
	this->_name = name;
    return ;
}


void	Zombie::announce( void )
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}