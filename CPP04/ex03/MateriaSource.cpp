#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

MateriaSource::MateriaSource( void )
{
    for (int i = 0; i < 4; i++)
        this->_allMateria[i] = NULL;
    return;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
        this->_allMateria[i] = other._allMateria[i];
    return ;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
            this->_allMateria[i] = other._allMateria[i];
    }
    return (*this);
} 

MateriaSource::~MateriaSource( void )
{
    for (int i = 0; i < 4; i++)
        delete _allMateria[i];
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
        AMateria* clone = _allMateria[same_type]->clone();
        return (clone);
    }
    std::cout << "* trying to create un unknown Materia*" << std::endl;
    return (0);
}
