#include "Base.hpp"

Base::~Base(){}

//  It randomly instanciates A, B or C and returns the instance as a Base pointer.
//  Feel free to use anything you like for the random choice implementation.


// Implicit conversion is done from "child" class to the "parent".
// No need to convert it.
Base *generate(void)
{
    // Generate a random nbr between 1 and 3 (include)
    std::srand(time(NULL));
    int randomNum = rand() % 3 + 1;

    std::cout << "randomNum: " << randomNum << std::endl;

    if (randomNum == 1)
    {
        std::cout << "An A class has been instanciates." << std::endl << std::endl;
        return (new A);
    }
    else if (randomNum == 2)
    {
        std::cout << "An B class has been instanciates." << std::endl << std::endl;
        return (new B);
    }
    else
    {
        std::cout << "An C class has been instanciates." << std::endl << std::endl;
        return (new C);
    }
}

// Check to wich case Base *p is related to.
// Display an error message if nothing has been founded.
void identify(Base* p)
{
    // If NULL > Casting Fail > it's not a type A.
    if (dynamic_cast<A*>(p) != NULL)
    {
        std::cout << "The type of the object is A." << std::endl;
    }
    else if (dynamic_cast<B*>(p) != NULL)
    {
        std::cout << "The type of the object is B." << std::endl;
    }
    else if (dynamic_cast<C*>(p) != NULL)
    {
        std::cout << "The type of the object is C." << std::endl;
    }
    else
    {
        std::cout << "Error: It's seems that p is not an A, b or C type." << std::endl;
    }
}

// Should use a try and catch
void identify(Base& p)
{
    try
    {
        A& tmp = dynamic_cast<A&>(p);
        std::cout << "The type of the object is &A." << std::endl;
        return ;
    }
    catch(...) // take any exeption
    {
        std::cout << "Conversion to A failed." << std::endl;
    }
    try
    {
        B& tmp = dynamic_cast<B&>(p);
        std::cout << "The type of the object is &B." << std::endl;
        return ;
    }
    catch(...)
    {
        std::cout << "Conversion to B failed." << std::endl;
    }
    try
    {
        // Try th edynamic cast to a tmp var
        C& tmp = dynamic_cast<C&>(p);
        std::cout << "The type of the object is &C." << std::endl;
        return ;
    }
    catch(...)
    {
        std::cout << "Conversion to C failed." << std::endl;
    }
    std::cout << "Conversion to a type &A, &b or &C failed." << std::endl;
}
