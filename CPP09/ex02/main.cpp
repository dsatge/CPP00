# include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
        return (0);
    try
    {
        PmergeMe *list = NULL;
        if (argc == 2)
            list = new PmergeMe(argv[1]);
        else
            list = new PmergeMe(argc, argv);
        list->sortFJohnosonAlgo();
        delete (list);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }
    
}
