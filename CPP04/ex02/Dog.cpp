#include "Dog.hpp"
#include "Brain.hpp"
#include "Animal.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

Dog::Dog( void ) : Animal::Animal()
{
    this->_type = "Dog";
    std::cout << "Default " << GREEN << "Dog" << RESET
            << " constructor" << std::endl;
    this->_brain = new Brain();
    return;
}

Dog::Dog(const Dog& other) : Animal::Animal(other)
{
    std::cout << GREEN << "Dog" << RESET << " copied"
            << std::endl;
    this->_brain = new Brain(*other._brain);
    return ;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete (this->_brain);
        this->_brain = new Brain(*other._brain);
    }
    return (*this);
} 

Dog::~Dog( void )
{
    delete (this->_brain);
    std::cout << GREEN << "dog" << RESET << " has been killed by the destructor" << std::endl;
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

void    Dog::makeSound(void) const
{
    std::cout << GREEN << "wouf wooouf" << RESET << std::endl;
}