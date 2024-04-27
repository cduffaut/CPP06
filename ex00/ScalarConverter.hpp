#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <cstdlib>

class   ScalarConverter
{
    private:
            ScalarConverter();
    public:
            static void convert(std::string literal);
            ~ScalarConverter();
};

#endif