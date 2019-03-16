#include <iostream>
#include <vector>
#include <string>

template <typename T>
class Stack;

template <typename T>
std::ostream& operator<<(std::ostream& os, Stack<T> const& st);

template <typename T>
class Stack {
    private:
        std::vector<T> elem_;
    public:
        void push(T const& elem);
        T pop();
        T const& top() const;

        // template function
        // case 1:
        /*
        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, Stack<U> const& st);
        */

        // case 2: declare a specialization of the nonmember function template as friend
        friend std::ostream& operator<< <T>(std::ostream& os, Stack<T> const& st);

        // non-template function, instantiated with class
        /*
        friend std::ostream& operator<<(std::ostream& os, Stack<T> const& st) {
            os << "in friend function" << std::endl;
            for(auto &x : st.elem_) os << x << std::endl;
            return os;
        }
        */

};

template <typename T>
void Stack<T>::push(T const& elem) {
    elem_.push_back(elem);
}

template <typename T>
T Stack<T>::pop() {
    T elem = elem_.back();
    elem_.pop_back();
    return elem;
}

template <typename T>
T const& Stack<T>::top() const {
    return elem_.back();
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Stack<T> const& st) {
    os << "in template function" << std::endl;
    for(auto &x : st.elem_) os << x << std::endl;
    return os;
}


template <typename T>
void display(T a) {
    std::cout << a << std::endl;
}

template <>
void display<int>(int a) {
    std::cout << "int:" << a << std::endl;
}

int main()
{
    static_assert(std::is_default_constructible<int>::value, "int is not constructible");

    Stack<int> a;
    a.push(2);
    a.push(3);
    std::cout << a;

    Stack<std::string> b;
    b.push("haha");
    b.push("hehe");
    std::cout << b;

    display(8);
    display("beautiful");

    int64_t c = -1;
    int64_t num = 0;
    num += c << 33;
    std::cout << num << std::endl;

    return 0;

}
