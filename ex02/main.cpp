#include "Base.hpp"

int main(void)
{
    std::cout << "---------- TEST : pointer identify -----------" << std::endl << std::endl;
    
    Base *Test = generate();

    identify(Test);

    // Pause so the time can be more random between the two tests.
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << std::endl << "---------- TEST : No pointer identify -----------" << std::endl << std::endl;

    Base *Test2 = generate();

    identify(*Test2);

    delete Test;
    delete Test2;
    return (0);
}