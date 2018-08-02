#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>

struct A
{
    public:
        std::array<int, 4> sc;

    public:
        A() : sc{0} {}
        void disp(){std::cout<<sc[0]<<std::endl;}
};

int main()
{
    std::array<int, 4> b = {{1, 2, 3, 4}};
    for(auto it=b.begin(); it != b.end(); it++){
        std::cout<<*it<<std::endl;
    }

    A a;
    a.disp();

    int c = {{1}};
    std::cout<<c<<std::endl;

    return 0;
}
