#include <iostream>

template <typename T1, typename T2>
auto adder(T1 a, T2 b) {
    return a+b;
}

int main()
{
    int a = 3, b = 5;
    auto rlt = adder<int, int>(3, 5);
    std::cout << rlt << std::endl;

    decltype(true ? a : b) c = a;
    std::cout << &a << std::endl;
    std::cout << &c << std::endl;

    return 0;
}
