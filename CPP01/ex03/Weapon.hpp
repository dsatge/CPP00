# include <iostream>

class	Weapon
{
	private:
		std::string _type;
		
	public:
		Weapon(std::string type);
		void Weapon::setType(std::string type);
		void Weapon::getType( void );
		~Weapon ( void );
};