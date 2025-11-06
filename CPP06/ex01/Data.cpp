# include "Data.hpp"

Data::Data(std::string name) : _name(name)
{
    return ;
}

Data::Data(const Data& other) : _name(other._name)
{
    return ;
}

Data& Data::operator=(const Data& other)
{
    if (this != &other)
    {
        this->_name = other._name;
    }
    return (*this);
}

Data::~Data(void)
{
    return ;
}