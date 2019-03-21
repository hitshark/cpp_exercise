#pragma once

#include <iostream>
#include <string>

template <typename T1, typename T2>
void logOut(T1 a, T2 b) {
    std::cout << a << " " << b << std::endl;
}

/*
template <typename T>
void logOut<T, char>(T a, char b) {
    std::cout << "function partial specialization" << std::endl;
    std::cout << a << " " << b << std::endl;
}
*/

template <typename T>
void logOut(T a, char b) {
    std::cout << "function template overloading" << std::endl;
    std::cout << a << " " << b << std::endl;
}

template <typename T>
void print(T a) {
    std::cout << "in template" << std::endl;
    std::cout << a << std::endl;
}

template<>
void print<std::string>(std::string a);

/*
template <>
void print<std::string>(std::string a) {
    std::cout << "in original function" << std::endl;
    std::cout << a << std::endl;
}
*/
