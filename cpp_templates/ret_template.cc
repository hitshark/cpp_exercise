#include <iostream>
#include <string>
#include "ret_template.h"

template <class T>
template <class U>
typename std::enable_if<is_one_of<U, char, int>::value>::type
Test<T>::print() const {
    std::cout << val_ << std::endl;
}

int main()
{
    Test<int> a(2);
    a.print<char>();
    a.print<std::string>();
    Test<std::string> b("haha");
    b.print();

    return 0;
}
