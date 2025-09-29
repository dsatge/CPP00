#include <iostream>
#include <fstream>
#include <sstream>

int	parsing(std::string s1)
{
	if (s1.length() == 0)
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

void	getwords(std::string s1, std::string s2, std::string &line, std::ifstream &infile, std::ofstream &outfile)
{
	int	len_find = std::string(s1).length();
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, len_find);
		line.insert(pos, s2);
		pos += std::string(s2).size();
	}
	outfile << line;
	if (!infile.eof())
		outfile << "\n";
}

int	main( void )
{
	std::string filename = "file.txt";
	std::string s1 = "a";
	std::string s2 = "aa";
	if (parsing(s1) == 1)
		return (1);
	std::ifstream infile(filename.c_str());
	if (check_infile(infile) == 1)
		return (1);
	std::string replaceFile = filename + ".replace";
	std::ofstream outfile(replaceFile.c_str());
	if (check_outfile(outfile) == 1)
		return (1);
	std::string line;
	while (std::getline(infile, line))
		getwords(s1, s2, line, infile, outfile);
	outfile.close();
	infile.close();
}
