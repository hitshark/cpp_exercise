#include <iostream>

template<typename U, typename... args>
struct is_one_of : public std::false_type {};
template <typename U, typename ... args>
struct is_one_of<U, U, args...> : public std::true_type {};
template < typename U, typename V, typename ... args>
struct is_one_of<U, V, args...> : public is_one_of<U, args...>{};

template <class T>
class Test {
private:
    T val_;
public:
    Test(T value) : val_(value) {}

    template<typename U = T>
    typename std::enable_if<is_one_of<U, char, int>::value>::type
    print() const;

    template<typename U = T>
    typename std::enable_if<!is_one_of<U, char, int>::value>::type
    print() const {
        std::cout << "default action" << std::endl;
    }
};

