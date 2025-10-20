#include "AMateria.hpp"
#include "MateriaIce.hpp"
#include "ICharacter.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

Ice::Ice( void ) : AMateria("Ice")
{
    return;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    return ;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return (*this);
} 

Ice::~Ice( void )
{
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

std::string const&  Ice::getType(void) const
{
    return (this->_type);
}


void Ice::use(ICharacter& target)
{
    std::cout << CYAN << "* shoots an ice bolt at " << target.getName() 
            << " *" << RESET << std::endl;
}
