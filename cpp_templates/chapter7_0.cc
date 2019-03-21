#include <iostream>
#include <type_traits>
#include <functional>

template <typename T>
T testPrint(T val) {
    val *= 2;
    std::cout << val << std::endl;
    return val;
}

int main()
{
    int a;
    auto b = (a = 3);
    std::cout << b << std::endl;
    if(std::is_same<decltype((a = 4)), int&>::value) std::cout << "type int" << std::endl;
    std::cout << a << std::endl;

    int c = 11;
    if(std::is_same<decltype(c), int>::value) std::cout << "c is int" << std::endl;
    if(std::is_same<decltype((c)), int&>::value) std::cout << "(c) is int&" << std::endl;

    if(std::is_same<std::decay<int &>::type, int>::value) std::cout << "int& decay to int" << std::endl;
    if(std::is_same<std::decay<const int &>::type, int>::value) std::cout << "const int& decay to int" << std::endl;

    double val = 3.14;
    auto ret = testPrint(val);
    std::cout << val << std::endl;
    if(std::is_same<decltype(ret), double>::value) std::cout << "double test" << std::endl;

    // std::ref(), std::cref()
    testPrint(std::ref(val));
    std::cout << val << std::endl;

    //testPrint("hello");
    //testPrint(std::string("xixi"));

    //const char str[] = "he";
    //auto ret_str = testPrint(str);
    //std::cout << ret_str << std::endl;
    //if(std::is_same<decltype(ret_str), char*>::value) std::cout << "char [] test" << std::endl;

    return 0;
}
