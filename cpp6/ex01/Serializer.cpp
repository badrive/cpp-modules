#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) { (void)other; }
Serializer& Serializer::operator=(const Serializer& other) { (void)other; return *this; }
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t num = reinterpret_cast<uintptr_t>(ptr);

    return num;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* num = reinterpret_cast<Data*>(raw);

    return num;
}
