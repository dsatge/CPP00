# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
// # include <ctime>
# include <cstdlib>

Base::~Base( void )
{
    return ;
}

Base* generate(void)
{
    srand(time(0));
    const int   rand_val = std::rand() % 3;
    switch (rand_val)
    {
    case 0 :
        std::cout << " A generated" << std::endl;
        return (new A);
    case 1 :
        std::cout << " B generated" << std::endl;
        return (new B);
    }
    std::cout << " C generated" << std::endl;
    return (new C);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A Identified." << std::endl;
        return ;
    }
    if (dynamic_cast<B*>(p))
    {
        std::cout << "B Identified." << std::endl;
        return ;
    }
    if (dynamic_cast<C*>(p))
    {
        std::cout << "C Identified." << std::endl;
        return ;
    }
    else
        std::cout << "Unknown base." << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A Identified." << std::endl;
        return ;
    }
    catch (std::exception &) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B Identified." << std::endl;
        return ;
    }
    catch (std::exception &) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C Identified." << std::endl;
        return ;
    }
    catch (std::exception &) {}
    std::cout << "Unknown base." << std::endl;
}
