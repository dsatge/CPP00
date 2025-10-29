#ifndef PRESIDENTIALPARDONFORM_HPP
    #define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
    protected:

    public:
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        /// Methods ///
        void execute(Bureaucrat const &executor);
        
        //// Exception ///
};

#endif