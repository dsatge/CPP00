# ifndef ITER_HPP
    # define ITER_HPP

# include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

template <typename T>
void iter(const T array[], const int arr_len, void (*func)(T const &))
{
    for (int i = 0; i < arr_len; i++)
        func(array[i]);
}

template <typename T>
void iter(T array[], const int arr_len, void (*func)(T &))
{
    for (int i = 0; i < arr_len; i++)
        func(array[i]);
}

template <typename T>
void print_content(const T content)
{
    std::cout << content << ", ";
    return ;
}

template <typename T>
void print_add_one(const T content)
{
    std::cout << content + 10 << ", ";
    return ;
}

template <typename T>
void increment(T &content)
{
    content++;
    return ;
}

# endif