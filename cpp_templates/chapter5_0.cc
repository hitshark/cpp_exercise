#include <vector>
#include <deque>
#include <memory>
#include <cassert>
#include <iostream>

template <typename T,
template <typename Elem, typename = std::allocator<Elem>>
class Cont = std::deque>
class Stack {
    private:
        Cont<T> elems_;

    public:
        void push(T const& elem);
        void pop();
        T const& top() const;
        bool empty() const {
            return elems_.empty();
        }

        template <typename T2,
        template <typename Elem2, typename = std::allocator<Elem2>>
        class Cont2>
        Stack<T, Cont>& operator= (Stack<T2, Cont2> const& st);

        friend std::ostream& operator<< (std::ostream& os, Stack<T, Cont> const& st) {
            os << "in friend function" << std::endl;
            return os;
        }
        template <typename, template<typename, typename> class>
        friend class Stack;
};


template <typename T, template <typename, typename> class Cont>
void Stack<T, Cont>::push(T const& elem) {
    elems_.push_back(elem);
}

template <typename T, template <typename, typename> class Cont>
void Stack<T, Cont>::pop() {
    assert(!elems_.empty());
    elems_.pop_back();
}

template <typename T, template <typename, typename> class Cont>
T const& Stack<T, Cont>::top() const {
    assert(!elems_.empty());
    return elems_.back();
}

template <typename T, template <typename, typename> class Cont>
template <typename T2, template <typename, typename> class Cont2>
Stack<T, Cont>& Stack<T, Cont>::operator= (Stack<T2, Cont2> const& st) {
    elems_.clear();
    elems_.insert(elems_.begin(), st.elems_.begin(), st.elems_.end());
    return *this;
}

int main()
{
    Stack<int> istack;
    istack.push(2);
    Stack<float, std::vector> fstack;
    fstack.push(1.1);

    std::cout << istack << std::endl;
    std::cout << fstack << std::endl;

    return 0;
}
