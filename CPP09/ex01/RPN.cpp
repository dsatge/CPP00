# include "RPN.hpp"

Rpn::Rpn(std::string line)
{

}

Rpn::Rpn(const Rpn &other)
{
    this->_stack = other._stack;
    return ;
}
        std::stack<std::string> _stack;
    public:
        Rpn(std::string line);
        Rpn(const Rpn &other);
        Rpn& operator=(const Rpn &other);
        ~Rpn();
