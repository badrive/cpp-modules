#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data  original;
    original.id   = 42;
    original.name = "Bender";

    Data* before = &original;

    uintptr_t raw   = Serializer::serialize(before);
    Data*     after = Serializer::deserialize(raw);

    std::cout << "before : " << before << std::endl;
    std::cout << "raw    : " << raw << std::endl;
    std::cout << "after  : " << after << std::endl;

    if (after == before)
        std::cout << "OK: same pointer, id=" << after->id
                  << " name=" << after->name << std::endl;
    else
        std::cout << "KO: pointers are different" << std::endl;
    return 0;
}
