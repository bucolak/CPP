#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data
{
    int id;
    std::string name;
};

class Serializer
{
    public:
        Serializer();
        Serializer(const Serializer &other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif