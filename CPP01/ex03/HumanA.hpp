# include <iostream>

class	HumanA
{
	private:
		std::string _Name;
		std::string _Weapon;

	public:
		HumanA(std::string Name, std::string Weapon);
		void HumanA::setName(std::string Name);
		void HumanA::setWeapon(std::string Weapon);
		void HumanA::attack( void );
		~HumanA( void );
};