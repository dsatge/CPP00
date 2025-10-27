# ifndef FORM_HPP
    #define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool              _signed;
        const int         _RequiredSigningGrade;
        const int         _RequiredExecuteGrade;

    public:
        Form(std::string name, int RequiredSigningGrade, int RequiredExecuteGrade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        void    beSigned(Bureaucrat& Bureaucrat);
        std::string getName() const;
        bool getSigned() const;
        int getRequiredSigningGrade() const;
        int getRequiredExecuteGrade() const;
        class GradeTooHigh : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };

        class GradeTooLow : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};
std::ostream& operator<<(std::ostream& out, const Form& other);

#endif