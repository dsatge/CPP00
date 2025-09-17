# include "HumanB.hpp"

HumanB::HumanB (std::string Name) : _Name(Name), _Weapon(NULL)
{
	return ;
}

HumanB::~HumanB ( void )
{
	return ;
}

void	HumanB::attack ( void )
{
	if (this->_Weapon == NULL)
	{
		std::cout << this->_Name 
			<< " forget to pick a weapon and is attacking bear hand"
			<< std::endl;
	}
	else
	{
		std::cout << this->_Name 
			<< " attacks with their "
			<< this->_Weapon->getType()
			<< std::endl;
	}
}