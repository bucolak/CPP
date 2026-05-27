#include "Serializer.hpp"

int main()
{
    Data dt;

    dt.id = 42;
    dt.name = "buket";
    Data* orgnlPtr = &dt;

    uintptr_t raw = Serializer::serialize(orgnlPtr);
    Data* newptr = Serializer::deserialize(raw);

    std::cout << "Original pointer : " << orgnlPtr << std::endl;
    std::cout << "Serialized value : " << raw << std::endl;
    std::cout << "Deserialized ptr : " << newptr << std::endl;

    std::cout << std::endl;

    if (orgnlPtr == newptr)
        std::cout << "Pointers are equal!" << std::endl;
    else
        std::cout << "Pointers are NOT equal!" << std::endl;

    std::cout << std::endl;

    std::cout << "ID   : " << newptr->id << std::endl;
    std::cout << "Name : " << newptr->name << std::endl;
    return 0;
}