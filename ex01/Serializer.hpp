#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

typedef struct s_Data
{
    uintptr_t   element;
}       Data;

/*
    Implement a class Serializer, 
    who will not be initializable by the user by any way:
    By using a private constructor and static methods
*/
class Serializer
{
    private:
            Serializer();

    public:
            ~Serializer();
            static uintptr_t serialize(Data* ptr);
            static Data* deserialize(uintptr_t raw);
};

#endif