# include <iostream>

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int arg = 1; arg < argc; arg++)
	{
		for (int i = 0; argv[arg][i]; i++)
			std::cout << (char)std::toupper(argv[arg][i]);
	}
	std::cout << std::endl;
	return (0);
}