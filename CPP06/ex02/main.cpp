# include "Base.hpp"

int main(void)
{
    Base *someKindOfBase = generate();
    std::cout << "recognise from pointer" << std::endl;
    identify(someKindOfBase);
    std::cout << "recognise from Reference" << std::endl;
    identify(*someKindOfBase);
    delete (someKindOfBase);
    return (0);
}