#include "AMateria.hpp"
#include "MateriaIce.hpp"
#include "ICharacter.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

Ice::Ice( void ) : AMateria("Ice")
{
    std::cout << "Materia Ice default constructor" << std::endl;
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
    std::cout << "Ice has been killed by the destructor" << std::endl;
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
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
