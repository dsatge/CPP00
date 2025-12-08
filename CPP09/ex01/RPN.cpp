# include "RPN.hpp"

Rpn::Rpn(std::string line) : _line(line)
{
    return ;
}

Rpn::Rpn(const Rpn &other) : _line(other._line)
{
    return ;
}

// Rpn& Rpn::operator=(const Rpn &other)
// {
//     return (*this);
// }

Rpn::~Rpn(void)
{
    return ;
}

bool    is_digit(std::string::const_iterator element)
{
    if (*element >= '0' && *element <= '9')
        return (true);
    return (false);
}

bool    is_operator(std::string::const_iterator element)
{
    if (*element == '+' || *element == '-'
            || *element == '*' || *element == '/')
        return (true);
    return (false);
}

bool    is_space(std::string::const_iterator element)
{
    if (*element == ' ')
        return (true);
    return (false);
}

double to_double(std::string::const_iterator element)
{
    char c = *element;
    return (c - '0');
}

double Rpn::calculate()
{
    std::stack<double> stack;
    std::string::const_iterator it;
    for (it = _line.begin(); it != _line.end(); it++)
    {
        if (is_digit(it) == true)
            stack.push(to_double(it));
        else if (is_operator(it) == true)
        {
            if (stack.size() < 2)
                throw MissingNumber();
            double rhs = stack.top();
            stack.pop();
            double lhs = stack.top();
            stack.pop();
            if (*it == '+')
                stack.push(lhs + rhs);
            if (*it == '-')
                stack.push(lhs - rhs);
            if (*it == '*')
                stack.push(lhs * rhs);
            if (*it == '/')
            {
                if (rhs == 0)
                    throw DivZero();
                stack.push(lhs / rhs);
            }
        }
        else if (is_space(it) == false)
            throw UnAuthorizedCharacter();
    }
    if (stack.size() > 1)
        throw MissingOperator();
    return (stack.top());
}

const char* Rpn::UnAuthorizedCharacter::what() const throw()
{
    return ("Unknown character.\nPlease retry with number between 0 and 9\nand operator +,-,*,/ only.");
}

const char* Rpn::MissingOperator::what() const throw()
{
    return ("Missing operator.\nNot enough number for calculation.");
}

const char* Rpn::MissingNumber::what() const throw()
{
    return ("Missing number.\nNot enough number for calculation.");
}

const char* Rpn::DivZero::what() const throw()
{
    return ("Impossible division by 0");
}
