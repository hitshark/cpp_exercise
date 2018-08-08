#include <tuple>
#include <utility>
#include <functional>
#include<algorithm>
#include <string>
#include <iostream>

int main()
{
    std::tuple<int, std::string, float> t1{10, "hello", 3.14};
    int score = std::get<0>(t1);
    std::string name = std::get<1>(t1);
    std::cout<<name<<" "<<score<<std::endl;

    std::tuple<int, int> t2 = std::make_tuple(10,11);
    std::cout<<std::get<1>(t2)<<std::endl;

    int x;
    std::tie(x, std::ignore, std::ignore) = t1;
    std::cout<<x<<std::endl;

    using type = std::tuple<int, std::string, float>;
    //std::tuple_element<2, type>::type first = std::get<2>(t1);
    std::tuple_element<2, decltype(t1)>::type first = std::get<2>(t1);
    std::cout<<first<<std::endl;

    int size = std::tuple_size<type>::value;
    std::cout<<size<<std::endl;

    return 0;
}
