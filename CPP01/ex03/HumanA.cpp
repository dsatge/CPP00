# include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon &Weapon) : _Name(Name), _Weapon(Weapon)
{
	return ;
}

HumanA::~HumanA ( void )
{
	return ;
}

void	HumanA::attack( void )
{
	std::cout << this->_Name 
		<< " attacks with their " 
		<< this->_Weapon.getType() 
		<< std::endl;
}
