# ifndef SERIALIZER_HPP
    # define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class Data;

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer&);
        ~Serializer();

    public:
        static uintptr_t serialized(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

# endif