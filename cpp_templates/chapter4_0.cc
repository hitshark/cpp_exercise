#include <iostream>

/*
template <typename T>
void print(T arg) {
    std::cout << arg << std::endl;
}

template <typename T, typename... Types>
void print(T farg, Types... args) {
    print(farg);
    print(args...);
}
*/

void print() {}

template <typename T, typename... Types>
void print(T farg, Types... args) {
    std::cout << farg << std::endl;
    std::cout << sizeof...(args) << std::endl;
    if(sizeof...(args) > 0) {
        print(args...);
    }
}

int main()
{
    print(2, "hello", 3.4);
    return 0;
}
