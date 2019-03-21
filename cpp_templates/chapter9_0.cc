#include <iostream>
#include <typeinfo>
#include <vector>

int main()
{
    unsigned int a = 2;
    std::string nm = "tom";
    std::vector<double> vb {1.0, 2.0};

    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid("hello").name() << std::endl;
    std::cout << typeid(nm).name() << std::endl;
    std::cout << typeid(vb).name() << std::endl;

    return 0;
}
