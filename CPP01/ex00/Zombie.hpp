#include <iostream>
#ifndef ZOMBIE_H
    #define ZOMBIE_H

class	Zombie {

	private:
		std::string _name;

	public:
		Zombie(std::string name);
		void	announce(void);
		~Zombie(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif