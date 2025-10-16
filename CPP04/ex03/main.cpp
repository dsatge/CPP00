#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

    return (0);
}

// Ce qu’il faut respecter (contraintes & pièges)
// Les classes abstraites (interfaces) ne peuvent pas être instanciées
// Les méthodes virtuelles pures (= 0) imposent aux dérivées de les implémenter
// Gérer la copie profonde (deep copy) pour Character et pour les AMateria
// unequip ne doit pas supprimer l’objet, mais “le libérer” du personnage (et il
// faut gérer ce qu’on fait de la materia détachée)
// Interface IMateriaSource doit apprendre et cloner
// Respecter les noms de fonctions, noms de classes, fichiers .hpp et .cpp comme indiqué
// Ne pas définir des méthodes dans le header (sauf templates)
// Attention aux fuites de mémoire (new/delete)
// Le programme doit implémenter tout ce qu’on demande, notamment les interactions entre matières, personnages, clonage