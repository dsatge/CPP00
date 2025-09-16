# include "HumanA.hpp"

HumanA::HumanA (std::string Name, std::string Weapon) : _Name(Name)
{
	this->_Name = Name;
	this->_Weapon = Weapon;
	return ;
}

HumanA::~HumanA ( void )
{
	return ;
}

void	HumanA::setName(std::string Name)
{
	this->_Name = Name;
}

void	HumanA::setWeapon(std::string Weapon)
{
	this->_Weapon = Weapon;
}

void	HumanA::attack( void )
{
	std::cout << this->_Name << " attacks with their " << this->_Weapon << std::endl;
}
