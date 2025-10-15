#include "Cat.hpp"
#include "Brain.hpp"
#include "Animal.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

Cat::Cat( void ) : Animal::Animal()
{
    this->_type = "Cat";
    std::cout << "Default " << CYAN << "Cat" << RESET
            << " constructor" << std::endl;
    this->_brain = new Brain();
    return;
}

Cat::Cat(const Cat& other) : Animal::Animal(other)
{
    std::cout << CYAN << "Cat" << RESET << " copied"
            << std::endl;
    this->_brain = new Brain(*other._brain);
    return ;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete (this->_brain);
        this->_brain = new Brain(*other._brain);
    }
    return (*this);
} 

Cat::~Cat( void )
{
    delete (this->_brain);
    std::cout << CYAN << "Cat" << RESET << " has been killed by the destructor" << std::endl;
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

void    Cat::makeSound(void) const
{
    std::cout << CYAN << "miaouuu" << RESET << std::endl;
}