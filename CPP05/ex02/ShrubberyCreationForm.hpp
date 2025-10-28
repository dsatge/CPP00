#ifndef SHRUBBERYCREATIONFORM_HPP
    #define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include <fstream>

class Shrubbery : public AForm
{
    protected:

    public:
        Shrubbery(std::string name);
        Shrubbery(const Shrubbery& other);
        Shrubbery& operator=(const Shrubbery& other);
        ~Shrubbery();

        /// Methods ///
        // std::string getName() const;
        // bool getSigned() const;
        // int getRequiredSigningGrade() const;
        // int getRequiredExecuteGrade() const;
        void execute(Bureaucrat const &executor);
        //// Exception ///
        class FailCreateOutfile : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class FailOpenWriteOutfile : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif