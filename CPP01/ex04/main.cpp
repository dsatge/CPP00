#include <iostream>
#include <fstream>
#include <sstream>

int	parsing(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "error: arg must contain filename followed by two words" << std::endl;
		return (1);
	}
	if (std::string(argv[2]).length() == 0)
	{
		std::cerr << "error: word to replace is empty" << std::endl;
		return (1);
	}
	return (0);
}

int	check_infile(std::ifstream &infile)
{
	if (!infile.is_open())
	{
		std::cerr << "error: file cannot be open" << std::endl;
		return (1);
	}
	if (!infile.good())
	{
		std::cerr << "error: file not readable" << std::endl;
		return (1);
	}
	return (0);
}

int	check_outfile(std::ofstream &outfile)
{
	if (!outfile)
	{
		std::cerr << "error: file cannot be created" << std::endl;
		return (1);
	}
	if (!outfile.good())
	{
		std::cerr << "error: no access permission" << std::endl;
		return (1);
	}
	return (0);
}

void	getwords(char **argv, std::string &line, std::ifstream &infile, std::ofstream &outfile)
{
	int	len_find = std::string(argv[2]).length();
	size_t pos = 0;
	while ((pos = line.find(argv[2], pos)) != std::string::npos)
	{
		line.erase(pos, len_find);
		line.insert(pos, argv[3]);
		pos += std::string(argv[3]).size();
	}
	outfile << line;
	if (!infile.eof())
		outfile << "\n";
}

int	main(int argc, char **argv)
{
	if (parsing(argc, argv) == 1)
		return (1);
	std::ifstream infile(argv[1]);
	if (check_infile(infile) == 1)
		return (1);
	std::string replaceFile = std::string(argv[1]) + ".replace";
	std::ofstream outfile(replaceFile.c_str());
	if (check_outfile(outfile) == 1)
		return (1);
	std::string line;
	while (std::getline(infile, line))
		getwords(argv, line, infile, outfile);
	outfile.close();
	infile.close();
}
