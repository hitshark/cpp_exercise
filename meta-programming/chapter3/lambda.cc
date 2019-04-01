#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/type_traits/is_same.hpp>

#include <iostream>
#include <string>

using namespace boost::mpl::placeholders;

template <class T1, class T2>
struct metaf {
    T1 name_;
    T2 age_;
    metaf(T1 nm, T2 age) : name_(nm), age_(age) {}
    static void print() {
        std::cout << "in print function" << std::endl;
    }

    typedef T1 type;
};

template <class T1, class F, class T2>
struct my_apply {
    typedef typename boost::mpl::lambda<F>::type meta_fc;
    typedef typename meta_fc::template apply<T1,T2>::type type;
    //typedef typename F::template apply<T1, T2>::type type;
};

int main()
{
    //typename my_apply<typename boost::mpl::lambda<metaf<_1, _2>>::type, std::string, int>::type nm;
    typename my_apply<std::string, metaf<_1,_2>, int>::type nm;

}
