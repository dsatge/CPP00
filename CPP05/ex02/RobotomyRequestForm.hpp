#ifndef ROBOTOMYREQUESTFORM_HPP
    #define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm
{
    protected:

    public:
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        /// Methods ///
        void execute(Bureaucrat const &executor);
        //// Exception ///
        class FailedRobotomy : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif