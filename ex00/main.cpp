#include "ScalarConverter.hpp"

int main(void)
{
    std::cout << "---------- FIRST SUBJECT TEST : 0 ----------" << std::endl;

    ScalarConverter::convert("0");

    std::cout << "---------- SECOND SUBJECT TEST : nan ----------" << std::endl;

    ScalarConverter::convert("nan");

    std::cout << "---------- THIRD SUBJECT TEST : 42.0f ----------" << std::endl;

    ScalarConverter::convert("42.0f");

    std::cout << "---------- EXTRA TEST : -56 ----------" << std::endl;

    ScalarConverter::convert("-56");    

    std::cout << "---------- EXTRA TEST : 89.23 ----------" << std::endl;

    ScalarConverter::convert("89.23");

    std::cout << "---------- EXTRA TEST : abcdef ----------" << std::endl;

    ScalarConverter::convert("abcdef");

    return (0);
}