# include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

void	Weapon::getType( void )
{
	std::cout << this->_type << std::endl;
}
