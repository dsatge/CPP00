#ifndef INTERN_HPP
    #define INTERN_HPP

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class AForm;

class Intern
{
    private:

    public:
        //Canonical form
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
        //Other
        AForm* makeForm(std::string formName, std::string target);
        static AForm* createShrubbery(std::string name);
        static AForm* createRobotomy(std::string name);
        static AForm* createPresidential(std::string name);
        //Exceptions
        class NoFormWithCorrespondingName : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif