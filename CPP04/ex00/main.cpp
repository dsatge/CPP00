#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "=========TEST FROM SUBJECT============\n" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete(i);
    delete(j);
    delete(meta);
    std::cout << "\n===============MY TESTS===============\n" << std::endl;
    std::cout << "=======================Animals" << std::endl;
    Animal* zoo = new Animal();
    zoo->makeSound();
    delete(zoo);
    std::cout << "=======================Dogs" << std::endl;
    Animal* a = new Dog();
    a->makeSound();
    delete(a);
    std::cout << "=======================Cats" << std::endl;
    Animal* b = new Cat();
    b->makeSound();
    delete(b);
    std::cout << "=======================WrongAnimals" << std::endl;
    WrongAnimal* wrongzoo = new WrongAnimal();
    wrongzoo->makeSound();
    delete(wrongzoo);
    std::cout << "=======================WrongCats" << std::endl;
    WrongAnimal* wrongcat = new WrongCat();
    wrongcat->makeSound();
    delete(wrongcat);
    std::cout << "===========PROOFS DIFF CLASSES============" << std::endl;
    // WrongAnimal* impossiblecat = new Cat();
    // Animal* impossibleanimal = new WrongAnimal();
}
