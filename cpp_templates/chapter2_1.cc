#include "chapter2_1.h"

/*
template<>
void print<std::string>(std::string a);

void print(std::string a) {
    std::cout << "in basic" << std::endl;
    std::cout << a << std::endl;
}
*/

template <>
void print<std::string>(std::string a) {
    std::cout << "in original function" << std::endl;
    std::cout << a << std::endl;
}

int main()
{
    print(2.33);
    print(std::string("hello"));
    logOut(3.14, 'c');
    return 0;
}
