# include "Serializer.hpp"
# include "Data.hpp"

int main(void)
{
    Data obj("My secret");
    Serializer *Key = NULL;
    uintptr_t cripted;

    std::cout << CYAN << "obj adress : " 
            << &obj << RESET << std::endl;
    cripted = Key->serialized(&obj);
    std::cout << "Serialization returns : " 
            << cripted << std::endl;
    std::cout << "cripted adress : " 
            << &cripted << std::endl;
    std::cout << CYAN << "deserialize returns : " 
            << Key->deserialize(cripted) << RESET << std::endl;
}