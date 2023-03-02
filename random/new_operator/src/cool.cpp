#include "cool.h"

template <typename T, size_t N>


Cool::Cool()
{
}

size_t Cool::GetArraySizeT(T (&a)[N])
{
    return N;
}