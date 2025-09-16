# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* Zomb = new Zombie[N];
    int i;

    i = 0;
    while (i < N)
    {
        Zomb[i].SetName(name);
        i++;
    }
    return (Zomb);
}