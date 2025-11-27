# include "Span.hpp"
# include <iostream>
# include <algorithm>

Span::Span(unsigned int listSize) : _listSize(listSize), _elementCount(0)
{
    
    return ;
}

Span::Span (const Span &other)
{
    this->_listSize = other._listSize;
    this->_elementCount = other._listSize;
}

Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_listSize = other._listSize;
        this->_elementCount = other._elementCount;
    }
    return (*this);
}

Span::~Span( void )
{
    return ;
}

void Span::addNumber(const int newVar)
{
    if (_listSize == _elementCount)
        throw ContainerFull();
    _elementCount++;
    _listContent.push_back(newVar);
    return ;
}

void Span::addXNumbers(const int Elements)
{
    srand(time(0));
    for (int i = 0; i < Elements; i++)
    {
        int random = rand();
        addNumber(random);
    }
}

int Span::shortestSpan(void)
{
    if (_elementCount == 0)
        throw ContainerEmpty();
    else if (_elementCount == 1)
        throw OneElement();
    std::sort(_listContent.begin(), _listContent.end());
    int minSpan = INT_MAX;
    std::vector<int>::iterator iteratorLeft = _listContent.begin();
    std::vector<int>::iterator iteratorRight = iteratorLeft + 1;
    for (unsigned int i = 0; i < (_elementCount - 1); i++)
    {
        long long diff = static_cast<long long>(iteratorRight[i])
            - static_cast<long long>(iteratorLeft[i]);
        if (diff < INT_MIN || diff > INT_MAX)
            throw OutOfRange();
        if (diff < minSpan)
            minSpan = static_cast<int>(diff);
    }
    return (minSpan);
}

int Span::longestSpan(void)
{
    if (_elementCount == 0)
        throw ContainerEmpty();
    if (_elementCount == 1)
        throw OneElement();
    std::sort(_listContent.begin(), _listContent.end());
    std::vector<int>::iterator iteratorList = _listContent.begin();
    long long span = static_cast<long long>(iteratorList[_elementCount - 1])
        - static_cast<long long>(iteratorList[0]);
    if (span < INT_MIN || span > INT_MAX)
        throw OutOfRange();
    return (static_cast<int>(span));
}


const char* Span::ContainerFull::what() const throw()
{
    return ("Container already full, cannot add new member");
}

const char* Span::ContainerEmpty::what() const throw()
{
    return ("Empty container, cannot compare members");
}

const char* Span::OneElement::what() const throw()
{
    return ("Only one element, cannot be compared");
}

const char* Span::OutOfRange::what() const throw()
{
    return ("Element value out of int range");
}
