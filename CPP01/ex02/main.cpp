# include <iostream>

int main( void )
{
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR;
    std::string& stringREF = string;

    stringPTR = &string;
    std::cout << "memory adress of string : " << &string << std::endl;
    std::cout << "memory adress of stringPTR : " << stringPTR << std::endl;
    std::cout << "memory adress of stringREF : " << &stringREF << std::endl;
 
    std::cout << "value of string : " << string << std::endl;
    std::cout << "value of stringPTR : " << *stringPTR << std::endl;
    std::cout << "value of stringREF : " << stringREF << std::endl;
}