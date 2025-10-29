# ifndef AFORM_HPP
    #define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool              _signed;
        const int         _RequiredSigningGrade;
        const int         _RequiredExecuteGrade;

    public:
        AForm(std::string name, int RequiredSigningGrade, int RequiredExecuteGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        void    beSigned(Bureaucrat& Bureaucrat);
        virtual void    execute(Bureaucrat const &executor) = 0;
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
        class ExecutionAutorisationInvalid : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class FormNotSigned : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};
std::ostream& operator<<(std::ostream& out, const AForm& other);

#endif