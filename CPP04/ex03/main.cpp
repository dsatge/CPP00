#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "MateriaCure.hpp"
#include "MateriaIce.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    {
        std::cout << YELLOW << "/////// TEST FROM SUBJECT ///////\n" << RESET << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("Ice");
        me->equip(tmp);
        tmp = src->createMateria("Cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    {
        std::cout << YELLOW << "\n/////// LEARN UNKOWN MATERIA ///////\n" << RESET << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Cure());
        src->learnMateria(new Cure());
        src->learnMateria(new Cure());
        src->learnMateria(new Cure());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("Ice");
        me->equip(tmp);
        tmp = src->createMateria("Cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bobby");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    {
        std::cout << YELLOW << "\n/////// EQUIP / UNEQUIP ///////\n" << RESET << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("Ice");
        me->equip(tmp);
        //// Removed Iced to put Cure to the first slop
        me->unequip(0);
        tmp = src->createMateria("Cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bobby");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    {
        std::cout << YELLOW << "\n/////// LIMITS MATERIA ///////\n" << RESET << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("Ice");
        me->equip(tmp);
        tmp = src->createMateria("Ice");
        me->equip(tmp);
        tmp = src->createMateria("Ice");
        me->equip(tmp);
        tmp = src->createMateria("Cure");
        me->equip(tmp);
        std::cout << YELLOW << "One too many Materia added to equipment :" << RESET << std::endl;
        tmp = src->createMateria("Cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bobby");
        me->use(-455, *bob);
        me->use(0, *bob);
        me->use(1, *bob);
        me->use(2, *bob);
        me->use(3, *bob);
        me->use(4, *bob);
        delete bob;
        delete me;
        delete src;
    }
    return (0);
}