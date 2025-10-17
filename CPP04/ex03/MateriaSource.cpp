#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

MateriaSource::MateriaSource( void )
{
    for (int i = 0; i < 4; i++)
        this->_allMateria[i] = NULL;
    std::cout << "Default MateriaSource constructor" << std::endl;
    return;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    // for (std::vector<AMateria*>::iterator it = _garbageMateria.begin(); it != _garbageMateria.end(); ++it)
    //     delete *it;
    for (int i = 0; i < 4; i++)
        this->_allMateria[i] = other._allMateria[i];
    return ;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        // for (std::vector<AMateria*>::iterator it = _garbageMateria.begin(); it != _garbageMateria.end(); ++it)
        //     delete *it;
        for (int i = 0; i < 4; i++)
            this->_allMateria[i] = other._allMateria[i];
    }
    return (*this);
} 

MateriaSource::~MateriaSource( void )
{
    // for (std::vector<AMateria*>::iterator it = _garbageMateria.begin(); it != _garbageMateria.end(); ++it)
    //     delete *it;
    std::cout << "MateriaSource has been killed by the destructor" << std::endl;
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

void MateriaSource::learnMateria(AMateria* materia)
{
    if (!materia)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (_allMateria[i] == NULL)
        {
            _allMateria[i] = materia;
            return ;
        }
    }
    delete (materia);
    return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    bool    type_exist = false;
    int i = 0;
    int same_type = 0;
    while (i < 4)
    {
        if (_allMateria[i] != NULL && _allMateria[i]->getType() == type)
        {
            type_exist = true;
            same_type = i;
        }   
        i++;
    }
    if (type_exist == true)
    {
        std::cout << "sans soucis ~~~ " << type << std::endl;
        AMateria* clone = _allMateria[same_type]->clone();
        std::cout << MAGENTA << "Resiste" << RESET << std::endl;
        return (clone);
    }
    std::cout << "okay bizard l ambiance" << std::endl;
    return (0);
}
