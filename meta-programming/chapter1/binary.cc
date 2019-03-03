#include <iostream>
#include "libs/mpl/book/chapter1/binary.hpp"

int main()
{
    std::cout << binary<101010>::value << std::endl;
    return 0;
}
