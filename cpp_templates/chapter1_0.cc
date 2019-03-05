#include <iostream>
#include <type_traits>

template <typename T1, typename T2>
//auto max(T1 a, T2 b) -> decltype(true ? a : b) {
//auto max(T1 a, T2 b) -> typename std::decay<decltype(true ? a : b)>::type {
typename std::common_type<T1, T2>::type max(T1 a,  T2 b) {
//std::common_type_t<T1, T2> max(T1 a, T2 b) {      // c++ 14
    return a < b ? b : a;
}

/*
template <typename T1, typename T2, typename RT = typename std::decay<decltype(true ? T1() : T2())>::type>
//template <typename T1, typename T2, typename RT = std::decay_t<decltype(true ? T1() : T2())>>
//template <typename T1, typename T2, typename RT = typename std::common_type<T1, T2>::type>
RT max(T1 a, T2 b) {
    return b < a ? a : b;
}
*/

const int& min(const int& a, const int& b) {
    const int& rlt = a > b ? a : b;
    return rlt;
}

int main()
{
    const int a = ::min(2, 3);
    for(int i = 0; i < 10; i++) int c = i;
    std::cout << a << std::endl;

    int n1 = 10;
    int n2 = 20;
    double n3 = 12.34;
    auto b = ::max(n1, n3);
    auto f = ::max(n1, n2);
    std::cout << b << std::endl;

    return 0;
}

