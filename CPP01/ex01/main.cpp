# include "Zombie.hpp"

int	main(void)
{
	int	N = 3;
	int	i;

	i = 0;
	if (N < 0)
		return (1);
	Zombie* Zomb = zombieHorde(N, "Didier");
	while (i < N)
	{
		Zomb[i].announce();
		i++;
	}
	delete [] Zomb;
	return (0);
}