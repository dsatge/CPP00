# include <iostream>

class Zombie {

    private :
        std::string _name;

    public :
        Zombie();
        void SetName(std::string name);
        void	announce( void );
        ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );