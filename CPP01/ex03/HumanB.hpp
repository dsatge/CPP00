#include "Weapon.hpp"
#include <iostream>
#ifndef HUMANB_HPP
    #define HUMANB_HPP

class	HumanB
{
	private:
		std::string _Name;
		Weapon *_Weapon;

	public:
		HumanB(std::string Name);
		void	attack( void );
		~HumanB( void );
};

#endif