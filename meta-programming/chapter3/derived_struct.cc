#include <iostream>

struct Base1 {
    typedef int type;
};

struct Derived1 : Base1 {};


template <class T>
struct Base {
    typedef T type;
};

template <class T>
struct Derived : Base<T> {};


int main()
{
    Derived<int>::type a = 5;
    std::cout << a << std::endl;

    Derived1::Base1::type b = 3;
    std::cout << b << std::endl;
    return 0;
}
