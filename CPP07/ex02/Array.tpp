# include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _array(NULL) , _arrayElementLen(0)
{
    return ;
}

template <typename T>
Array<T>::Array(unsigned int n) : _arrayElementLen(n)
{
    this->_array = new T[n];
    return ;
}

template <typename T>
Array<T>::Array(const Array<T> & other)
{
    this->_array = other._array;
    this->_arrayElementLen = other._arrayElementLen;
    return ;
}

template <typename T>
T& Array<T>::operator=(const Array<T> &other)
{
    if (this != other)
    {
        this->_array = other._array;
        this->_arrayElementLen = other._arrayElementLen;
    }
    return (this*);
}

template <typename T>
T& Array<T>::operator[](const Array<T> &other)
{
    if ([] > other._arrayElementLen)
        throw ArrayIndexUnexist();
    return (other._array[]);
}


template <typename T>
Array<T>::~Array(void)
{
    for (int i = 0; i < this->_arrayElementLen; i++)
        delete (Array[i]);
    return ;
}

template <typename T>
const char* Array<T>::ArrayIndexUnexist::what() const throw()
{
    return ("Index out of bound")
}