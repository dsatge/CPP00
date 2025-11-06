# include "Serializer.hpp"

Serializer::Serializer(void)
{
    return ;
}

Serializer::Serializer(const Serializer&)
{
    return ;
}

Serializer& Serializer::operator=(const Serializer&)
{
    return (*this);
}

Serializer::~Serializer(void)
{
    return ;
}

//// Methods

uintptr_t Serializer::serialized(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
