# include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << this->_name << " :";
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << this->_name << " is now destroyed" << std::endl;
    return ;
}

void    Zombie::announce( void )
{
    std::cout << " BraiiiiiiinnnzzzZ..." << std::endl;
}