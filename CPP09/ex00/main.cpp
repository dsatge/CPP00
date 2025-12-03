# include "BitcoinExchange.hpp"
# include <fstream>

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    try
    {
        BitcoinExchange mapList = BitcoinExchange();
        std::cout << "Checkpoint" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error : " << e.what() << RESET << '\n';
    }
    return (0);
}

// Verifier fichier donne
// Mettre dans la forme map via la classe: avec exceptions
// mettre en mode gnl le nouveau fichier ligne par ligne et mettre 
//      le try and catch ici que si il y a un probleme le prog continu
// checker chaque date:
//  -est ce que la date est avant les premieres data
//  -est ce que la date est dans le tableau -> oui, juste afficher
//  -sinon aller a la date la plus proche (celle en dessou) si revenu au debut ...
//  -sinon remonter a celle d avant.



// EXCEPTIONS
// format fichier avec Date | Valeur
// val positive
// je sais plus