#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

template <typename T>
using EnableCondition = typename std::enable_if<std::is_constructible<std::string, T>::value>::type;
//using EnableCondition = std::enable_if_t<std::is_constructible<std::string, T>::value>;   // c++14
//using EnableCondition = std::enable_if_t<std::is_constructible_v<std::string, T>>;        // c++17

class Exp {
    private:
        std::string name;
    public:
        template <typename T, typename = EnableCondition<T>>
        explicit Exp(T&& nm) : name(std::forward<T>(nm)) {
            std::cout << "template constructor" << std::endl;
        }
        Exp(Exp const& obj) : name(obj.name) {
            std::cout << "copy constructor lvalue" << std::endl;
        }
        Exp(Exp&& obj) : name(std::move(obj.name)) {
            std::cout << "copy constructor rvalue" << std::endl;
        }

        Exp() {}

        void print() const {
            std::cout << name << std::endl;
        }
};

int main()
{
    std::string s("hi");
    Exp p1(s);
    Exp p2("hello");
    Exp p3(p1);
    Exp p4(std::move(p1));

    return 0;
}
