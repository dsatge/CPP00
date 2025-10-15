#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "////// EXEMPLE FROM SUBJECT //////\n" << std::endl;    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    std::cout << "\n////// TABLE : half Dog - half Cats //////\n" << std::endl;
    Animal* animals[10];
    for (int i = 0; i < 5; i++)
        animals[i] = new Dog();
    for (int i = 5; i < 10; i++)
        animals[i] = new Cat();
    
    std::cout << "\n////// Listen to each animal from the table //////\n" << std::endl;    
    for (int i = 0; i < 10; i++)
        animals[i]->makeSound();

    std::cout << "\n////// Kill all animal from the table //////\n" << std::endl;    
    for (int i = 0; i < 10; i++)
        delete (animals[i]);

    std::cout << "\n////// Test Brainless Cat aka Wrong cat //////\n" << std::endl;    
    const WrongAnimal* zombie_cat = new WrongCat();
    zombie_cat->makeSound();
    delete (zombie_cat);

    std::cout << "\n////// Test Class animal : plus possible //////\n" << std::endl;    
    // Animal* typeofbird = new Animal();
    // typeofbird->makeSound();
    // delete (typeofbird);

    return (0);
}