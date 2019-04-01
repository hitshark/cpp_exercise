#include <boost/static_assert.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/apply.hpp>
#include <iostream>

using namespace boost::mpl::placeholders;
namespace mpl = boost::mpl;

template <class F, class T>
struct apply1 : F::template apply<T> {};

template <class F, class T>
struct twice {
    typedef typename F::template apply<T>::type once;
    typedef typename F::template apply<once>::type type;
};

template <class F, class T>
struct twice_2 : apply1<F, typename apply1<F, T>::type> {};

template <class F, class T>
struct twice_3 : mpl::apply<F, typename mpl::apply<F,T>::type> {};

struct add_pointer_f {
    template <class T>
    struct apply {
        typedef typename boost::add_pointer<T>::type type;
    };
};

template <class X>
struct two_pointers : twice<mpl::lambda<boost::add_pointer<_1>>::type, X> {};

int main()
{
    BOOST_STATIC_ASSERT((
                ::boost::is_same<twice<add_pointer_f, int>::type, int**>::value
                ));
    BOOST_STATIC_ASSERT((
                ::boost::is_same<two_pointers<int>::type, int**>::value
                ));

    return 0;
}
