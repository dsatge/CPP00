#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "MateriaCure.hpp"
#include "MateriaIce.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

AMateria::AMateria(std::string const& type) : _type(type)
{
    std::cout << "Default AMateria constructor" << std::endl;
    return;
}

AMateria::AMateria(const AMateria& other)
{
    this->_type = other._type;
    return ;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
} 

AMateria::~AMateria( void )
{
    std::cout << "AMateria has been destructoyed" << std::endl;
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

std::string const&  AMateria::getType(void) const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
