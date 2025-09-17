# include <iostream>
# include "Weapon.hpp"
#ifndef HUMANA_HPP
    #define HUMANA_HPP

class	HumanA
{
	private:
		std::string _Name;
		Weapon &_Weapon;

	public:
		HumanA(std::string Name, Weapon &Weapon);
		void	attack( void );
		~HumanA( void );
};

#endif