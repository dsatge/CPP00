# include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    std::cout << YELLOW << "Use member fonctions from std::stack :" << RESET << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << GREEN << "Top" << RESET << " of stack = " << mstack.top() << std::endl;
    //remove first element
    mstack.pop();
    std::cout << GREEN << "Pop" << RESET << " after = " << mstack.top() << std::endl;
    std::cout << GREEN << "Size" << RESET << " = " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Use of iterators:
    std::cout << YELLOW << "Use member function needing iterators :" << RESET << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    std::cout << GREEN << ".begin() = " << RESET << *it << std::endl;
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << GREEN << ".end() = " << RESET << *ite << std::endl;
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << GREEN << "++ as next element = " << RESET << *it << std::endl;
        ++it;
    }

    std::cout << YELLOW << "Copy check :" << RESET << std::endl;
    std::stack<int> s(mstack);
    MutantStack<int> copy(mstack);
    MutantStack<int>::iterator itcopy = copy.begin();
    MutantStack<int>::iterator itecopy = copy.end();
    ++itcopy;
    --itcopy;
    while (itcopy != itecopy)
    {
        std::cout << MAGENTA << "copy = " << RESET << *itcopy << std::endl;
        ++itcopy;
    }

    std::cout << YELLOW << "Test Reverse iterator :" << RESET << std::endl;
    MutantStack<int>::reverse_iterator itrev = copy.rbegin();
    MutantStack<int>::reverse_iterator iterev = copy.rend();
    ++itrev;
    --itrev;
    while (itrev != iterev)
    {
        std::cout << MAGENTA << "rev = " << RESET << *itrev << std::endl;
        ++itrev;
    }

    return 0;
}