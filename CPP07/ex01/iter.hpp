# ifndef ITER_HPP
    # define ITER_HPP

# include <iostream>

template <typename T>
void iter(T array[], int arr_len, void (*f)(<T>ref))
{
    for (int i = 0; i < arr_len; i++)
        (*f).array[i];
};
# endif