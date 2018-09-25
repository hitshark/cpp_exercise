#include <functional>
#include <vector>
#include <iostream>

void fun1(std::vector<int> & vec) {
    for(auto x : vec) std::cout<<x<<" ";
    std::cout<<std::endl;
}

int main()
{
    auto lambda = [](int a) -> int{return a;};
    std::function<void(std::vector<int> &)> func1;
    func1 = fun1;
    std::vector<int> dat{1,2,3,4};
    func1(dat);

    std::cout<<lambda(10)<<std::endl;

    return 0;
}
