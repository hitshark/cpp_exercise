#include <type_traits>
#include <iterator>
#include <vector>
#include <iostream>

template <bool use_swap> struct iter_swap_impl;
template <>
struct iter_swap_impl<true> {
    template < class ForwardIterator1, class ForwardIterator2>
    static void do_it(ForwardIterator1 i1, ForwardIterator2 i2) {
        std::swap(*i1, *i2);
    }
};

template <>
struct iter_swap_impl<false> {
    template < class ForwardIterator1, class ForwardIterator2>
    static void do_it(ForwardIterator1 i1, ForwardIterator2 i2) {
        typename std::iterator_traits<ForwardIterator1>::value_type tmp = *i1;
        *i1 = *i2;
        *i2 = tmp;
    }
};

template < class ForwardIterator1, class ForwardIterator2>
void iter_swap(ForwardIterator1 i1, ForwardIterator2 i2) {
    typedef std::iterator_traits<ForwardIterator1> traits1;
    typedef typename traits1::value_type v1;
    typedef typename traits1::reference r1;

    typedef std::iterator_traits<ForwardIterator2> traits2;
    typedef typename traits2::value_type v2;
    typedef typename traits2::reference r2;

    bool const use_swap = std::is_same<v1, v2>::value &&
                          std::is_reference<r1>::value &&
                          std::is_reference<r2>::value;
    iter_swap_impl<use_swap>::do_it(i1, i2);
}


int main()
{
    std::vector<int> a = {1,2,3,4};
    std::vector<long> b = {11,12};
    using iter = std::vector<int>::iterator;
    std::cout << "(" << a[0] << "," << b[0] << ")" << std::endl;
    ::iter_swap(a.begin(), b.begin());
    std::cout << "(" << a[0] << "," << b[0] << ")" << std::endl;

    return 0;
}
