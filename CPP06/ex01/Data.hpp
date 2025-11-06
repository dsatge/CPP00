# ifndef DATA_HPP
    # define DATA_HPP

#include <iostream>

class Data
{
    private:
        std::string _name;
    public:
        Data(std::string name);
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data();
};

#endif