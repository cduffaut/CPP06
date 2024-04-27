#include "Serializer.hpp"

int main(void)
{
    Data        *dataTest;
    Data        *dataTmp;
    uintptr_t   uTest = 777;

    dataTest = new Data;

    std::cout << "--------- FIRST TEST: From Data to uint to Data ---------\n" << std::endl;

    std::cout << "Valeur avant double conversion: " << dataTest << std::endl;

    uTest = Serializer::serialize(dataTest);
    dataTmp = Serializer::deserialize(uTest);
    uTest = Serializer::serialize(dataTest);

    std::cout << "Valeur après double conversion: " << dataTmp << std::endl << std::endl;

    std::cout << "--------- SECOND TEST: From uint to Data to uint ---------\n" << std::endl;

    std::cout << "Valeur avant double conversion: " << uTest << std::endl;

    dataTest = Serializer::deserialize(uTest);
    uTest = Serializer::serialize(reinterpret_cast<Data *>(dataTest));

    std::cout << "Valeur après double conversion: " << uTest << std::endl << std::endl;

    std::cout << "--------- *FAIL TEST*: From uint to Data to *WRONG* uint ---------\n" << std::endl;

    std::cout << "Valeur avant double conversion: " << uTest << std::endl;

    dataTest = Serializer::deserialize(uTest);
    uTest = Serializer::serialize(reinterpret_cast<Data *>(123));

    std::cout << "Valeur après double conversion: " << uTest << std::endl;

    delete dataTest;
    return (0);
}