# ifndef WHATEVER_HPP
    # define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T &lhs, T &rhs)
{
    T tmp;

    tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

template <typename T>
T const &min(const T &lhs, const T &rhs)
{
    return (lhs < rhs ? lhs : rhs);
}

template <typename T>
T const &max(const T &lhs, const T &rhs)
{
    return (lhs > rhs ? lhs : rhs);
}

# endif