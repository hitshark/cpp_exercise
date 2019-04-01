#include <boost/mpl/vector.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/placeholders.hpp>

#include <string>
#include <iostream>

namespace mpl = boost::mpl;
// type sequence
typedef mpl::vector<signed char, short, int, long> signed_types;
typedef mpl::vector<mpl::int_<1>, mpl::int_<0>, mpl::int_<0>, mpl::int_<0>,
                    mpl::int_<0>, mpl::int_<0>, mpl::int_<0>> mass;
typedef mpl::vector<mpl::int_<0>, mpl::int_<1>, mpl::int_<0>, mpl::int_<0>,
                    mpl::int_<0>, mpl::int_<0>, mpl::int_<0>> length;

// integral sequence wrapper
//typedef mpl::vector_c<int,1,0,0,0,0,0,0> mass;
//typedef mpl::vector_c<int,0,1,0,0,0,0,0> length;

// quantity definition
template <class T, class Dimension>
struct quantity {
    explicit quantity(T x) : m_value(x) {}
    template <class otherD>
    quantity(const quantity<T, otherD> &q) : m_value(q.value()) {
        BOOST_STATIC_ASSERT((
                    mpl::equal<Dimension, otherD>::type::value
                    ));
    }
    T value() const { return m_value; }
private:
    T m_value;
};

typedef quantity<float, mass> mass_num;
typedef quantity<float, length> length_num;

// addition and subtraction
template <class T, class Dimension>
quantity<T, Dimension> operator+(quantity<T, Dimension> x, quantity<T, Dimension> y) {
    return quantity<T, Dimension>(x.value() + y.value());
}

template <class T, class Dimension>
quantity<T, Dimension> operator-(quantity<T, Dimension> x, quantity<T, Dimension> y) {
    return quantity<T, Dimension>(x.value() - y.value());
}

// meta-function class
struct plus_f {
    template <class T1, class T2>
    struct apply {
        typedef typename mpl::plus<T1, T2>::type type;
    };
};

// meta-function forwarding
struct minus_f {
    template <class T1, class T2>
    struct apply : mpl::minus<T1, T2> {};
};

// multiplication
template <class T, class D1, class D2>
quantity<T, typename mpl::transform<D1, D2, plus_f>::type>
operator*(quantity<T, D1> x, quantity<T, D2> y) {
    return quantity<T, typename mpl::transform<D1, D2, plus_f>::type>(x.value() * y.value());
}

//division
using namespace mpl::placeholders;
template <class T, class D1, class D2>
quantity<T, typename mpl::transform<D1, D2, mpl::minus<_1, _2>>::type>
operator/(quantity<T, D1> x, quantity<T, D2> y) {
    return quantity<T, typename mpl::transform<D1, D2, mpl::minus<_1, _2>>::type> (x.value() / y.value());
}

template <class D1, class D2>
struct dim_transform : mpl::transform<D1, D2, mpl::minus<_1, _2>> {};

template <class T, class D1, class D2>
quantity<T, typename dim_transform<D1, D2>::type>
customDivison(quantity<T, D1> x, quantity<T, D2> y, std::string &log) {
    std::cout << log << std::endl;
    return quantity<T, typename dim_transform<D1, D2>::type>(x.value() / y.value());
}



int main()
{
    mass_num a(2.0f);
    mass_num c(3.0f);
    length_num b(1.4f);
    std::cout << (a+c).value() << std::endl;
    std::cout << (a-c).value() << std::endl;
    std::cout << (a*b).value() << std::endl;
    std::cout << (a/b).value() << std::endl;

    return 0;
}
