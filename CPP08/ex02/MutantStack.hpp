# ifndef MUTANTSTACK_HPP
    # define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

template <typename T>
class MutantStack : public std::stack<T>
{
    private :
    public :
        MutantStack();
        MutantStack(const MutantStack<T> &other);
        MutantStack<T>& operator=(const MutantStack<T> &other);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        
        // iterator / const iterator
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        // reverse iterator / const reverse iterator
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;
};

# include "MutantStack.tpp"

# endif
