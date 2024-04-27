#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(std::string convert)
{
    // Init the tab for the literals cases:
    std::string pseudoLiterals[6] = {"-inff", "-inf", "+inff", "+inf", "nanf", "nan"};
    // Init main variables:
    std::string toChar = "";
    int toInt = 0;
    float toFloat = 0;
    double toDouble = 0;

    // Check if it is only a valid char
    // Func: isprint -> check if a char is printable.
    // Func: isdigit -> check if it is a digit.
    if (convert.length() == 1 && (!std::isdigit(convert[0])) && std::isprint(convert[0]))
    {
        toChar = convert[0];
        std::cout << "char: " << toChar[0] << std::endl;
        std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
        return ;
    }

    // ---------- CHAR CASE -----------

    // Convert first the std::string in Int
    toInt = std::atoi(convert.c_str());
    // *Check the specials cases first*
    for (int i = 0; i < 6; i++)
    {
        if (convert == pseudoLiterals[i])
        {
            toChar = "impossible";
            break ;
        }
    }
    // If not: check if char is printable
    if (std::isprint(toInt) && toChar == "")
    {
        toChar = "'";
        toChar += static_cast<char>(toInt);
        toChar += "'";
    }
    else if (toChar == "")
    {
        toChar = "Non displayable";
    }
    std::cout << "char: " << toChar << std::endl;

    // ---------- INT CASE -----------

    std::istringstream iss(convert);

    // Try to convert in int
    if (!(iss >> toInt))
    {
        // Conversion failed
        std::cout << "int: " << "impossible" << std::endl;
    } else {
        // The conversion has been a success!
        std::cout << "int: " << toInt << std::endl;
    }

    // ---------- FLOAT & DOUBLE CASE -----------

    // **First: let's see if it is a special case**
    for (int i = 0; i < 6; i++)
    {
        if (convert == pseudoLiterals[0] || convert == pseudoLiterals[1])
        {
            std::cout << "float: " << "-inff" << std::endl;
            std::cout << "double: " << "-inf" << std::endl;
            return ;          
        }
        else if (convert == pseudoLiterals[2] || convert == pseudoLiterals[3])
        {
            std::cout << "float: " << "+inff" << std::endl;
            std::cout << "double: " << "+inf" << std::endl;
            return ;
        }
        else if (convert == pseudoLiterals[4] || convert == pseudoLiterals[5])
        {
            std::cout << "float: " << "nanf" << std::endl;
            std::cout << "double: " << "nan" << std::endl;
            return ;          
        }
    }
    // Check if the format float is valid
    char    *endptr;
    toFloat = std::strtod(convert.c_str(), &endptr);
    if (*endptr != '\0' && (*endptr != 'f' && *++endptr != '\0'))
    {
        std::cout << "float: " << "impossible" << std::endl;
        std::cout << "double: " << "impossible" << std::endl;       
    }
    else
    {
        if ((toFloat - (int)toFloat) == 0)
        {
            std::cout << "float: " << toFloat << ".0f" << std::endl;
            std::cout << "double: " << toFloat << ".0" << std::endl;
        }
        else
        {
            std::cout << "float: " << toFloat << "f" << std::endl;
            std::cout << "double: " << toFloat << std::endl;
        }
    }
}
