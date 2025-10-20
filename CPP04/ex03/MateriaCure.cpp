#include "ICharacter.hpp"
#include "MateriaCure.hpp"
#include "AMateria.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

Cure::Cure( void ) : AMateria("Cure")
{
    return;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    return ;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return (*this);
} 

Cure::~Cure( void )
{
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

std::string const&  Cure::getType(void) const
{
    return (this->_type);
}

void Cure::use(ICharacter& target)
{
    std::cout << GREEN << "* heals " << target.getName() << " wounds *" 
            << RESET << std::endl;
}
