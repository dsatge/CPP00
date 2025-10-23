#ifndef BUREAUCRAT_HPP
    #define BUREAUCRAT_HPP

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

class Bureaucrat
{
    private:
        std::string const   _name;
        int                 _grade;

    public:
        //Canonical form
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        //Other
        Bureaucrat(std::string name, int grade);
        const std::string getName( void ) const;
        int         getGrade( void ) const;
        void        incrementGrade( void );
        void        decrementGrade( void );

        //Exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif