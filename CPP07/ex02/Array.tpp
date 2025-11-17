# include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _array(NULL) , _arrayElementLen(0)
{
    return ;
}

template <typename T>
Array<T>::Array(unsigned int n) : _arrayElementLen(n)
{
    _array = new T[n];
    return ;
}

template <typename T>
Array<T>::Array(const Array<T> & other)
{
    _arrayElementLen = other._arrayElementLen;
    if (_arrayElementLen == 0)
    {
        _array = NULL;
        return;
    }
    _array = new T[_arrayElementLen];
    for (unsigned int i = 0; i < _arrayElementLen; i++)
        _array[i] = other._array[i];
    return ;
}

template <typename T>
T& Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        delete[] _array;
        _arrayElementLen = other._arrayElementLen;
        _array = new T[_arrayElementLen];
        for (int i = 0; i < _arrayElementLen; i++)
            _array[i] = other._array[i];
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _arrayElementLen)
        throw ArrayIndexUnexist();
    return (_array[index]);
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _arrayElementLen)
        throw ArrayIndexUnexist();
    return (_array[index]);
}


template <typename T>
Array<T>::~Array(void)
{
    delete[] _array;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return (_arrayElementLen);
}

template <typename T>
std::ostream& operator<<(std::ostream &out, const Array<T> arr)
{
    out << arr;
    return (out);
}


template <typename T>
const char* Array<T>::ArrayIndexUnexist::what() const throw()
{
    return ("Index out of bound");
}